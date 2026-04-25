default_target := main.out
debug_target := debug.out
sanitized_target := san.out

target ?= $(default_target)

# dirs
lib_dir := lib
build_dir := build

# sources
sources := $(shell find $(lib_dir) -name '*.cpp')
headers := $(shell find $(lib_dir) -name '*.hpp')
objs := $(patsubst $(lib_dir)/%.cpp,$(build_dir)/%.o,$(sources))

# compiler setup
CXX := g++
CXXSTD := c++17
CXXFLAGS := -std=$(CXXSTD) -I$(lib_dir) -g
CXXFLAGS += -Wall -Wextra -Wno-strict-aliasing

ifeq ($(target),$(debug_target))
	CXXFLAGS += -O0 -D_GLIBCXX_DEBUG
else ifeq ($(target),$(sanitized_target))
	CXXFLAGS += -O1 -fsanitize=address,undefined
else
	CXXFLAGS += -O2
endif

CLANGDB := compile_commands.json

MAKEFLAGS += --no-print-directory

main := main.cpp
main_in := $(build_dir)/in.txt
main_out := $(build_dir)/out.txt
main_exp := $(build_dir)/exp.txt

bin := $(build_dir)/$(target)

# run main
all: $(bin) $(main_in) $(main_out)
	@./$< < $(main_in) > $(main_out)
	@cat $(main_out)

time: $(bin) $(main_in) $(main_out)
	@/usr/bin/time -v ./$< < $(main_in) > $(main_out)
	@cat $(main_out)

compare: $(bin) $(main_in) $(main_out) $(main_exp)
	@./$< < $(main_in) > $(main_out)
	@paste $(main_exp) $(main_out) | awk -F'\t' '$$1 != $$2 {printf ":%d:\n%s\n%s\n", NR, $$1, $$2}'

interactive: $(bin)
	@./$<

debug: $(bin)
	@$(MAKE) target=$(debug_target) debug_run

debug_run: $(bin)
	@gdb $<

sanitize:
	@$(MAKE) target=$(sanitized_target)

test:

$(main_in):
	@touch $(main_in)

$(main_out):
	@touch $(main_out)

$(main_exp):
	@touch $(main_exp)

.PHONY: all time compare interactive debug debug_run sanitize test

# utils
format: $(sources) $(headers)
	@clang-format -i $^

lint: $(CLANGDB) $(sources) $(headers)
	@clang-tidy -p . $^

clangdb: clean-clangdb
	@$(MAKE) $(CLANGDB)

.PHONY: format lint clangdb

# compilation
$(bin): $(main) | $(build_dir)
	@$(CXX) $(CXXFLAGS) $< -o $@

$(build_dir)/%.o: $(lib_dir)/%.cpp $(headers) | $(build_dir)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(CLANGDB): $(sources) $(headers)
	@$(MAKE) clean
	@bear -- $(MAKE) $(objs)

$(build_dir):
	@mkdir -p $(build_dir)

# clean
clean:
	@rm -rf $(build_dir)

clean-clangdb:
	@rm -f $(CLANGDB)
	@rm -rf .cache/clangd

clean-all: clean clean-clangdb

.PHONY: clean clean-clangdb clean-all
