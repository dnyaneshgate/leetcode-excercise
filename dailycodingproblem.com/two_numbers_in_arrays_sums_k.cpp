/*
 * This problem was recently asked by Google.
 *
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 *
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 */

#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    for (auto x : nums) {
        int y = abs(k - x);
        if (mp.count(y)) {
            return true;
        }
        mp[x] = 1;
    }
    return false;
}

int main() {
    struct test_t {
        vector<int> arr;
        int k;
        bool expected;
    };

    vector<test_t> tests = {
        {{10, 15, 3, 7}, 17, true},
        {{10, 15, 3, 7}, 18, true},
        {{10}, 19, false},
        {{}, 19, false},
    };

    for (auto &t : tests) {
        assert(check(t.arr, t.k) == t.expected);
    }

    return 0;
}
