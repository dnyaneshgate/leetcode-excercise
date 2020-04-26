/*
 * Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
 *
 * Example 1:
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
 * Example 2:
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 * Note: The length of the given binary array will not exceed 50,000.
 */

/*
 * OTHER BEST SOLUTIONS
 *
 * class Solution {
 * public:
 *     int findMaxLength(vector<int>& nums) {
 *         if (nums.size() == 0) {
 *             return 0;
 *         }
 *
 *         // 0 1   = 2
 *         // 0 0 0 1 = 2
 *
 *         // 1111111110101011111111111111110101010101001010010101001
 *         // 12345678989898
 *         // 00000000000000
 *         // 00000000011223
 *
 *         int best = 0;
 *
 *         const int NO_POS = -2;
 *         const int n = nums.size();
 *
 *         vector ar_pos(n*2 + 2, NO_POS);
 *         int sum = 0;
 *         ar_pos[n + sum] = -1;
 *         for(int idx = 0; idx < n; idx++) {
 *             sum += (nums[idx] == 0 ? -1 : 1);
 *
 *             int& pos(ar_pos[n+sum]);
 *             if (pos == NO_POS) {
 *                 pos = idx;
 *             } else {
 *                 int len = idx - pos;
 *                 if (best < len) best = len;
 *             }
 *         }
 *
 *         return best;
 *     }
 * };
 */

#include <bits/stdc++.h>

using namespace std;

int maxLen(vector<int> &nums) {
    unordered_map<int, int> mp;
    int sum = 0, max_len = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += (nums[i] == 0) ? -1 : 1;

        if (sum == 0) {
            max_len = i + 1;
        }

        if (mp.find(sum) != mp.end()) {
            max_len = max(max_len, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return max_len;
}

int findMaxLength(vector<int> &nums) {
    return maxLen(nums);
}

int main() {
    struct test_t {
        vector<int> nums;
        int expected;
    };

    vector<test_t> tests = {
        {{0, 1, 0, 1, 0}, 4},
        {{0, 1, 0, 1, 1}, 4},
        {{0, 1, 0, 1, 0, 0, 1}, 6},
        {{1, 0, 1, 1, 1, 0, 0}, 6},
        {{1, 1, 1, 1}, 0},
        {{0, 0, 1, 1, 0}, 4},
        {{0}, 0},
        {{}, 0},
    };

    for (auto &t : tests) {
        int ret = findMaxLength(t.nums);
        cout << ret << endl;
        assert(ret == t.expected);
    }
    return 0;
}
