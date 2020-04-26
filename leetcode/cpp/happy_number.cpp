/**
 * Write an algorithm to determine if a number n is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer,
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Return True if n is a happy number, and False if not.
 *
 * Example:
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */

/**
 * 18
 * 1 + 64 = 65
 * 36 + 25 = 61
 * 36 + 1 = 37
 * 9  + 49 = 58
 * 25 +
 */

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> map_;

bool isHappy(int num) {
    if (num == 1)
        return true;
    if (map_.find(num) != map_.end())
        return false;

    map_[num] = 1;

    int n = num;
    int s = 0;

    while (n > 0) {
        int i = n % 10;
        s += i * i;
        n = n / 10;
    }

    return isHappy(s);
}

int main() {
    struct test {
        int num;
        bool expected;
    };

    vector<test> tests = {
        {19, true},
        {17, false},
    };

    for (auto t : tests) {
        assert(isHappy(t.num) == t.expected);
    }
    return 0;
}
