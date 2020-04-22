/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int curr_max = nums[0];
    int max_so_far = nums[0];
    for(int i=1; i<nums.size(); i++) {
        // printf("curr_max: %d, nums[i]: %d, max_so_far: %d\n", curr_max, nums[i], max_so_far);
        curr_max = max(nums[i], curr_max + nums[i]);
        max_so_far = max(curr_max, max_so_far);
        // printf("\t\tcurr_max: %d, nums[i]: %d, max_so_far: %d\n\n", curr_max, nums[i], max_so_far);
    }
    return max_so_far;
}

int main() {
    struct test {
        vector<int> arr;
        int expected;
    };

    vector<test> tests = {
        {{-2,1,-3,4,-1,2,1,-5,4}, 6},
        {{4,-1,2,1}, 6},
    };

    for(auto t: tests) {
        int ret = maxSubArray(t.arr);
        cout << ret << endl;
        assert(ret == t.expected);
    }

}
