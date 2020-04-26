/*
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid.
 * We define the validity of a string by these rules:
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 * An empty string is also valid.
 *
 * Example 1:
 * Input: "()"
 * Output: True
 *
 * Example 2:
 * Input: "(*)"
 * Output: True
 *
 * Example 3:
 * Input: "(*))"
 * Output: True
 *
 * Note:
 *      The string size will be in the range [1, 100].
 */

/*
 * bool checkValidString(string s) {
 *     stack<int> star,validpar;
 *
 *     for(int i=0;i<s.size();i++)
 *     {
 *         if(s[i]=='(')validpar.push(i);
 *         else if(s[i]=='*')star.push(i);
 *         else
 *         {
 *             if(!validpar.empty())validpar.pop();
 *             else if(!star.empty())star.pop();
 *             else
 *                 return false;
 *         }
 *     }
 *
 *     while(!star.empty()&&!validpar.empty())
 *     {
 *         if(validpar.top()>star.top())
 *             return false;
 *
 *         star.pop();validpar.pop();
 *     }
 *
 *     return validpar.empty();
 * }
 */

#include <bits/stdc++.h>

using namespace std;

bool check(string &s, stack<char> st, int start, int end) {
    // cout << "check: " << string(s, start, end) << ", start=" << start << ", end=" << end << endl;
    for (int i = start; i <= end; ++i) {
        if (s[i] == '(') {
            st.push(s[i]);
            continue;
        }

        if (s[i] == ')') {
            if (st.empty())
                return false;
            if (st.top() != '(')
                return false;
            st.pop();
            continue;
        }

        if (s[i] == '*') {
            if (check(s, st, i + 1, end))
                return true;
            // else cout << " *=' ' test failed " << endl;

            s[i] = '(';
            if (check(s, st, i, end))
                return true;
            // else cout << " *='(' test failed " << endl;

            s[i] = ')';
            if (check(s, st, i, end))
                return true;
            // else cout << " *=')' test failed " << endl;

            return false;
        }
    }

    return st.empty();
}

bool checkValidString(string s) {
    stack<char> st;
    return check(s, st, 0, s.length() - 1);
}

int main() {
    struct test_t {
        string str;
        bool expected;
    };

    vector<test_t> tests = {
        // { "()",     true },
        // { "(*)",    true },
        // { "(***)",  true },
        // { "(*())",  true },
        {"(*))", true},
        {"(*)))", false},
        {"(*))*)", true},
        {")", false},
        {")*", false},
        {"(", false},
        {"(*()", true},
        {"((*)", true},
    };

    int i = 0;
    for (auto &t : tests) {
        bool ret = checkValidString(t.str);
        cout << "Test " << i++ << ": " << ret << endl;
        assert(ret == t.expected);
    }

    return 0;
}
