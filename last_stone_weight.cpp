/*
 * We have a collection of stones, each stone has a positive integer weight.
 *
 * Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:
 *
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
 * At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
 *
 *
 *
 * Example 1:
 *
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 * we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 * we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 *
 *
 * Note:
 *
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 */


#include <bits/stdc++.h>

using namespace std;


int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> q(stones.begin(), stones.end());
    while(!q.empty() && q.size() > 1) {
        int s1 = q.top();
        q.pop();
        int s2 = q.top();
        q.pop();

        q.push(abs(s1-s2));
    }

    if(q.empty()) {
        return 0;
    }

    int ret = q.top();
    q.pop();
    return ret;
}

int main () {
    struct test_t {
        vector<int> arr;
        int expected;
    };

    vector<test_t> tests = {
        {{2,7,4,1,8,1}, 1},
    };

    for(auto &t: tests) {
        assert( lastStoneWeight(t.arr) == t.expected );
    }

    return 0;
}
