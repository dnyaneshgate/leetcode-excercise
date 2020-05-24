"""
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
"""

from collections import namedtuple


class Solution:
    def __init__(self):
        self.dp = {0: 0, 1: 1, 2: 1}

    def tribonacci(self, n: int) -> int:
        if n in self.dp:
            return self.dp[n]

        ret = self.tribonacci(n - 1) + self.tribonacci(n - 2) + self.tribonacci(n - 3)

        self.dp[n] = ret

        return ret


if __name__ == "__main__":
    Test = namedtuple("Test", "num expected")
    tests = [
        Test(num=0, expected=0),
        Test(num=1, expected=1),
        Test(num=2, expected=1),
        Test(num=4, expected=4),
        Test(num=25, expected=1389537),
        Test(num=37, expected=2082876103),
    ]

    for t in tests:
        s = Solution()
        assert (s.tribonacci(t.num) == t.expected)
