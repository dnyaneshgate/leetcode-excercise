/*
 * Given an integer array arr, count element x such that x + 1 is also in arr.
 *
 * If there're duplicates in arr, count them seperately.
 *
 *
 *
 * Example 1:
 *
 * Input: arr = [1,2,3]
 * Output: 2
 * Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
 * Example 2:
 *
 * Input: arr = [1,1,3,3,5,5,7,7]
 * Output: 0
 * Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
 * Example 3:
 *
 * Input: arr = [1,3,2,3,5,0]
 * Output: 3
 * Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
 * Example 4:
 *
 * Input: arr = [1,1,2,2]
 * Output: 2
 * Explanation: Two 1s are counted cause 2 is in arr.
 *
 *
 * Constraints:
 *
 * 1 <= arr.length <= 1000
 * 0 <= arr[i] <= 1000
 */

#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int countElements1(vector<int> &arr) {
    if (arr.size() < 2) {
        return 0;
    }
    sort(arr.begin(), arr.end());
    int ret = 0;
    int dup = 1;
    for (int i = 1; i < arr.size(); ++i) {
        if ((arr[i] - arr[i - 1] == 1)) {
            ret += dup;
            dup = 1;
        } else if (arr[i - 1] == arr[i]) {
            ++dup;
        } else {
            dup = 1;
        }
    }
    return ret;
}

int countElements(vector<int> &arr) {
    if (arr.size() < 2) {
        return 0;
    }
    unordered_map<int, int> mp;
    for (auto &i : arr) {
        mp[i]++;
    }
    int ans = 0;
    for (auto &i : mp) {
        if (mp.count(i.first + 1)) {
            ans += i.second;
        }
    }
    return ans;
}

int main() {
    struct test {
        vector<int> arr;
        int expected;
    };

    vector<test> tests = {
        {{1, 2, 3}, 2},
        {{1, 1, 3, 3, 5, 5, 7, 7}, 0},
        {{1, 3, 2, 3, 5, 0}, 3},
        {{1, 1, 2, 2}, 2},
    };

    for (auto &t : tests) {
        int ret = countElements(t.arr);
        cout << ret << endl;
        assert(ret == t.expected);
    }
    return 0;
}
