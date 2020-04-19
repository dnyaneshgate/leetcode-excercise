/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * Example 1:
 *
 * Input: [2,2,1]
 * Output: 1
 * Example 2:
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 */

#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ret = nums[0];
    for(int i=1; i<nums.size(); i++)
        ret ^= nums[i];
    return ret;
}

int main() {
    struct test {
        vector<int> arr;
        int expected;
    };

    vector<test> tests = {
        {{2,2,1}, 1},
        {{4,1,2,1,2}, 4},
    };

    for(auto t: tests) {
        int ret = singleNumber(t.arr);
        cout << ret << endl;
        assert(ret == t.expected);
    }
}
