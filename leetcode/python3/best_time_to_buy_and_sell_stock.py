"""
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
"""

from typing import List


class Solution:
    def _maxProfit(self, prices: List[int]) -> int:
        profit: int = 0
        buy: int = -1
        for i in range(1, len(prices)):
            # print("Buy:", buy, "Prev:", prices[i - 1], "Day:", i, "Price:", prices[i])
            if buy == -1 and prices[i - 1] < prices[i]:
                buy = prices[i - 1]
                # print("Buy:", buy)
            elif buy != -1 and prices[i - 1] > prices[i]:
                profit += prices[i - 1] - buy
                buy = -1
                # print("Sell:", prices[i - 1], "Profit:", profit)
        if buy != -1:
            profit += prices[-1] - buy
        # print("Input:", prices, "Profit:", profit)
        return profit

    def maxProfit(self, prices: List[int]) -> int:
        s = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                s += (prices[i] - prices[i - 1])

        return (s)


if __name__ == "__main__":
    from collections import namedtuple

    Test = namedtuple("Test", "input expected")
    tests: List[Test] = [
        Test(input=[7, 1, 5, 3, 6, 4], expected=7),
        Test([1, 2, 3, 4, 5], 4),
        Test([7, 6, 4, 3, 1], 0),
    ]

    s = Solution()
    for t in tests:
        assert (s.maxProfit(t.input) == t.expected)
