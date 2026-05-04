# vim X.py in && python3 X.py < in
import sys
cin = sys.stdin.readline
cout = sys.stdout.write

def perr(*args):
	import inspect
	frame = inspect.currentframe().f_back
	line = inspect.getframeinfo(frame).code_context[0]
	inside = line[line.find('(')+1:line.rfind(')')]
	names = [s.strip() for s in inside.split(',')]
	for name, val in zip(names, args):
		print(f"{name} = {val}", file=sys.stderr)

INF = 10**18
NINF = -10**18

t=int(cin())
for _ in range(t):
	pass
