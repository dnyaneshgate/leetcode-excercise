/*
 * The Tribonacci sequence Tn is defined as follows:
 *
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 *
 * Given n, return the value of Tn.
 *
 *
 *
 * Example 1:
 *
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 * Example 2:
 *
 * Input: n = 25
 * Output: 1389537
 *
 *
 * Constraints:
 *
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> dp_;

public:
    int tribonacci(int n) {
        switch (n) {
        case 0:
            return 0;
        case 1:
        case 2:
            return 1;
        }

        if (dp_.count(n)) {
            return dp_[n];
        }

        int ret = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        dp_[n]  = ret;

        return ret;
    }
};

int main() {
    struct test_t {
        int num;
        int expected;
    };

    vector<test_t> tests = {
        {0, 0},
        {1, 1},
        {2, 1},
        {4, 4},
        {25, 1389537},
        {37, 2082876103},
    };

    for (const auto &t : tests) {
        Solution s;
        assert(s.tribonacci(t.num) == t.expected);
    }
}
