/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);
 * Example 1:
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> ret(numRows);
        int step = -1;
        int row  = 0;
        for (const auto &c : s) {
            ret[row] += c;
            if (row == 0 || row == numRows - 1) {
                step *= -1;
            }
            row += step;
        }

        string result;
        for (const auto &str : ret) {
            result += str;
        }

        return result;
    }
};

int main() {
    struct test_t {
        string str;
        int n;
        string expected;
    };

    vector<test_t> tests = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"AB", 1, "AB"},
    };

    Solution s;
    for (const auto &t : tests) {
        assert(s.convert(t.str, t.n) == t.expected);
    }

    return 0;
}
