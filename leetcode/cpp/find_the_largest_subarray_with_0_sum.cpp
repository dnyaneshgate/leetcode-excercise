/*
 * Find the length of largest subarray with 0 sum
 * Given an array of integers, find the length of the longest sub-array with sum equals to 0.
 * Examples :
 *
 * Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
 * Output: 5
 * Explanation: The longest sub-array with
 * elements summing up-to 0 is {-2, 2, -8, 1, 7}
 *
 * Input: arr[] = {1, 2, 3}
 * Output: 0
 * Explanation:There is no subarray with 0 sum
 *
 * Input:  arr[] = {1, 0, 3}
 * Output:  1
 * Explanation: The longest sub-array with
 * elements summing up-to 0 is {0}
 */

#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int> &nums) {
    unordered_map<int,int> mp;
    int sum = 0, max_len = 0;

    for(int i=0; i<nums.size(); ++i) {
        sum += nums[i];

        if(nums[i] == 0 && max_len == 0) {
            max_len = 1;
        }

        if(sum == 0) {
            max_len = i + 1;
        }

        if(mp.find(sum) != mp.end()) {
            max_len = max(max_len, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return max_len;
}

int main() {
    struct test_t {
        vector<int> nums;
        int expected;
    };

    vector<test_t> tests = {
        { {15, -2, 2, -8, 1, 7, 10, 23}, 5 },
        { {15, -2, 2, -8, 1, 7, -15, 23}, 7 },
        { {0, 1, 2,3,5}, 1 },
        { {-1, 1, 2,3,5}, 2 },
        { {1, 1, 2,3,5}, 0 },
    };

    for(auto &t: tests) {
        assert(maxLen(t.nums) == t.expected);
    }

    return 0;
}
