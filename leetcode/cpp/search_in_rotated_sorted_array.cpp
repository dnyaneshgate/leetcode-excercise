/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */

#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int search(vector<int> &nums, int target, int start, int end) {
    if (start > end) {
        return -1;
    }
    return 0;
}

int search(vector<int> &nums, int target) {
}

int main() {
    struct test_t {
        vector<int> nums;
        int target;
        int expected;
    };

    vector<test_t> tests = {
        {{4, 5, 6, 7, 0, 1, 2}, 4, 0},
        {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
    };

    for (auto &t : tests) {
        assert(search(t.nums, t.target) == t.expected);
    }

    return 0;
}
