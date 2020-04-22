/*
 * You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
 *
 * direction can be 0 (for left shift) or 1 (for right shift).
 * amount is the amount by which string s is to be shifted.
 * A left shift by 1 means remove the first character of s and append it to the end.
 * Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
 * Return the final string after all operations.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "abc", shift = [[0,1],[1,2]]
 * Output: "cab"
 * Explanation:
 * [0,1] means shift to left by 1. "abc" -> "bca"
 * [1,2] means shift to right by 2. "bca" -> "cab"
 * Example 2:
 *
 * Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
 * Output: "efgabcd"
 * Explanation:
 * [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
 * [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
 * [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
 * [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 100
 * s only contains lower case English letters.
 * 1 <= shift.length <= 100
 * shift[i].length == 2
 * 0 <= shift[i][0] <= 1
 * 0 <= shift[i][1] <= 100
 */


#include <bits/stdc++.h>

using namespace std;


// alternate
string stringRotation(string s, vector<vector<int>>& rotation) {
    int n = s.length();
    for(auto & r : rotation) {
        int d = r[0], cnt = r[1] % n;
        if (d == 0) rotate(s.begin(), s.begin() + cnt, s.end());
        else rotate(s.begin(), s.begin() + n - cnt, s.end());
    }
    return s;
}

string stringShift(string s, vector<vector<int>>& shifts) {

    auto rshift = [](list<char> &str, int n) {
        while(n--) {
            str.push_front( str.back() );
            str.pop_back();
        }
    };

    auto lshift = [](list<char> &str, int n) {
        while(n--) {
            str.push_back( str.front() );
            str.pop_front();
        }
    };

    list<char> l(s.begin(), s.end());
    for(auto &shift: shifts) {
        switch(shift[0]) {
            case 0:
                lshift(l, shift[1]);
                break;
            case 1:
                rshift(l, shift[1]);
                break;
        }
    }

    return string(l.begin(), l.end());
}

int main () {
    struct test_t {
        string s;
        vector<vector<int>> shifts;
        string expected;
    };

    vector<test_t> tests = {
        { "abc", {{0,1},{1,2}}, "cab" },
        { "abcdefg", {{1,1},{1,1},{0,2},{1,3}}, "efgabcd" },
    };

    for(auto &t: tests) {
        assert( stringShift(t.s, t.shifts) == t.expected );
        assert( stringRotation(t.s, t.shifts) == t.expected );
    }

    return 0;
}
