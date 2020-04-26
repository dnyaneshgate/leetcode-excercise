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

int search_rec(vector<int> &nums, int target, int start, int end) {
    if (start > end) {
        return -1;
    }

    if (start == end && nums[start] != target) {
        return -1;
    }

    if (start == end && nums[start] == target) {
        return start;
    }

    int mid = (start + end) / 2;

    int found = search_rec(nums, target, start, mid);
    if (found != -1) {
        return found;
    }

    found = search_rec(nums, target, mid + 1, end);
    if (found != -1) {
        return found;
    }

    return -1;
}

int search1(vector<int> &nums, int target) {
    return search_rec(nums, target, 0, nums.size() - 1);
}

int search2(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i += 2) {
        if (nums[i] == target) {
            return i;
        }
        if (i < nums.size() - 1 && nums[i + 1] == target) {
            return i + 1;
        }
    }
    return -1;
}

int findPivot(vector<int> &nums, int low, int high) {
    if (low > high) {
        return -1;
    }

    if (low == high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (mid < high && nums[mid] > nums[mid + 1]) {
        return mid + 1;
    }

    if (mid > low && nums[mid - 1] > nums[mid]) {
        return mid;
    }

    if (nums[mid] > nums[high]) {
        return findPivot(nums, mid + 1, high);
    }

    return findPivot(nums, low, mid);
}

int bisearch(vector<int> &nums, int target, int low, int high) {
    if (low > high) {
        return -1;
    }

    if (low == high && nums[low] == target) {
        return low;
    }

    int mid = (low + high) / 2;

    if (nums[mid] == target) {
        return mid;
    }

    if (target < nums[mid]) {
        return bisearch(nums, target, low, mid - 1);
    }

    return bisearch(nums, target, mid + 1, high);
}

int search(vector<int> &nums, int target) {
    int p = findPivot(nums, 0, nums.size() - 1);
    if (p == -1) {
        return bisearch(nums, target, 0, nums.size() - 1);
    }

    if (nums[p] == target) {
        return p;
    }

    if (nums[0] <= target) {
        return bisearch(nums, target, 0, p - 1);
    }

    return bisearch(nums, target, p + 1, nums.size() - 1);
}

int main() {
    struct test_t {
        vector<int> nums;
        int target;
        int expected;
    };

    vector<test_t> tests = {
        {{4, 5, 6, 7, 8, 0, 1, 2}, 4, 0},
        {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
        {{8, 1, 2, 3, 4, 5, 6}, 0, -1},
    };

    for (auto &t : tests) {
        // cout << search(t.nums, t.target) << endl;
        assert(search(t.nums, t.target) == t.expected);
    }

    return 0;
}
