/*
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Example:
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
 *
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

/*
 * vector<int> productExceptSelf(vector<int>& nums) {
 *     int n = nums.size();
 *     vector<int> result(n, 1);
 *
 *     for (int i = 1; i < n; i++){
 *         result[i] = result[i-1]*nums[i-1];
 *     }
 *
 *     int right = 1;
 *     for (int i = n-1; i >= 0; i--){
 *         result[i] *= right;
 *         right *= nums[i];
 *     }
 *
 *     return result;
 *
 * }
 */

/*
 * vector<int> productExceptSelf(vector<int>& nums) {
 *     vector<int> ans(nums.size());
 *     int pre[nums.size()], post[nums.size()];
 *     pre[0] = 1;
 *     post[nums.size()-1]= 1;
 *     for(int i= 1; i<nums.size(); i++){
 *         pre[i] = pre[i-1]*nums[i-1];
 *     }
 *     for(int i = nums.size()-2; i>=0; i--){
 *         post[i] = post[i+1]*nums[i+1];
 *     }
 *     for(int i = 0; i<nums.size(); i++){
 *         ans[i] = post[i]*pre[i];
 *     }
 *     return ans;
 * }
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    int index = -1, zeros = 0, product = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0 && index == -1) {
            index = i;
        } else if (nums[i] == 0 && index != -1) {
            product = 0;
            break;
        } else {
            product *= nums[i];
        }
    }

    vector<int> ret(nums.size(), 0);

    if (!product) {
        return ret;
    }

    if (index != -1) {
        ret[index] = product;
        return ret;
    }

    for (int i = 0; i < nums.size(); ++i) {
        ret[i] = (product / nums[i]);
    }

    return ret;
}

int main() {

    struct test_t {
        vector<int> nums;
        vector<int> expected;
    };

    vector<test_t> tests = {
        // { {1,2,3,4}, {24,12,8,6} },
        // { {1,2,0,4}, {0,0,8,0} },
        // { {0,1}, {1,0} },
        // { {0,1,0}, {0,0,0} },
        // { {5,9,2,-9,-9,-7,-8,7,-9,10}, {} },
        // { {5,9,2,-9,-9,-7,-8,7,-9,10}, {-51438240,-28576800,-128595600,28576800,28576800,36741600,32148900,-36741600,28576800,-25719120}},
        {{1, 1, 1, 1, -1, 1, 5, 1, -1, -1, -1, 1, -1, 1, -3, 1, 1, 1, 1, 1, 1, 1, -1, 1, -1, 1, 1, 5, -1, 1, -1, 1, 1, 3, -1, -5, -1, 1, -1, 1, -1, -3, 1, 2, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, -1, -1, -1, -3, -1, -1, 4, -1, 1, -1, 1, -1, -1, -1, -1, 3, 1, 4, -5, -1, 1, 1, 1, 1, 1, -4, 1, 1, -3, -1, -1, 1, 3, -1, 1, -2, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1}, {349920000, 349920000, 349920000, 349920000, -349920000, 349920000, 69984000, 349920000, -349920000, -349920000, -349920000, 349920000, -349920000, 349920000, -116640000, 349920000, 349920000, 349920000, 349920000, 349920000, 349920000, 349920000, -349920000, 349920000, -349920000, 349920000, 349920000, 69984000, -349920000, 349920000, -349920000, 349920000, 349920000, 116640000, -349920000, -69984000, -349920000, 349920000, -349920000, 349920000, -349920000, -116640000, 349920000, 174960000, -349920000, 349920000, -349920000, 349920000, -349920000, 349920000, 349920000, 349920000, 349920000, 349920000, -349920000, -349920000, -349920000, -116640000, -349920000, -349920000, 87480000, -349920000, 349920000, -349920000, 349920000, -349920000, -349920000, -349920000, -349920000, 116640000, 349920000, 87480000, -69984000, -349920000, 349920000, 349920000, 349920000, 349920000, 349920000, -87480000, 349920000, 349920000, -116640000, -349920000, -349920000, 349920000, 116640000, -349920000, 349920000, -174960000, 349920000, -349920000, 349920000, 349920000, 349920000, -349920000, 349920000, 349920000, 349920000, -349920000}},
    };

    for (auto &t : tests) {
        assert(productExceptSelf(t.nums) == t.expected);
    }

    return 0;
}
