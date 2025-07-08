#include <bits/stdc++.h>
#include <limits>

using namespace std;

#define IO_OPTIMIZATIONS                                                       \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

#define SETUP IO_OPTIMIZATIONS;

typedef long long num;

num local_min(vector<num> &nums, size_t i, size_t j) {
    num local_min = numeric_limits<num>::max();
    for (; i < j; i++) {
        if (nums[i] < local_min)
            local_min = nums[i];
    }
    return local_min;
}
num local_max(vector<num> &nums, size_t i, size_t j) {
    num local_max = numeric_limits<num>::min();
    for (; i < j; i++) {
        if (nums[i] > local_max)
            local_max = nums[i];
    }
    return local_max;
}

int main(int argc, char *argv[]) {
    SETUP;
    size_t t;
    cin >> t;

    /*vector<num> nums(n);*/
    /*for (size_t i = 0; i < n; i++) {*/
    /*    cin >> nums[i];*/
    /*}*/

    size_t n;
    vector<num> nums;
    for (size_t i = 0; i < t; i++) {
        cin >> n;

        nums.resize(n);
        for (size_t j = 0; j < n; j++) {
            cin >> nums[j];
        }

        bool reducible;
        num global_min = local_min(nums, 0, nums.size()), num;
        for (size_t j = 0; j < n; j++) {
            num = nums[j];
            if (num == local_min(nums, 0, j + 1)) {
                reducible = true;
                for (size_t k = j + 1; k < nums.size(); k++) {
                    if (num > nums[k])
                        continue;
                    reducible = num < local_max(nums, k, nums.size());
                }
            } else if (num == local_max(nums, j, nums.size())) {
                reducible = true;
                for (size_t k = j; k > 0; k--) {
                    if (num < nums[k - 1])
                        continue;
                    reducible = num > local_min(nums, 0, k);
                }
            } else
                reducible = false;
            cout << (reducible ? "1" : "0");
        }
        cout << endl;
    }

    return 0;
}
