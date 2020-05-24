"""
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"

 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string s, int numRows);
 Example 1:

 Input: s = "PAYPALISHIRING", numRows = 3
 Output: "PAHNAPLSIIGYIR"
 Example 2:

 Input: s = "PAYPALISHIRING", numRows = 4
 Output: "PINALSIGYAHRPI"
 Explanation:

 P     I    N
 A   L S  I G
 Y A   H R
 P     I
"""
from collections import namedtuple


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        mat = []
        for i in range(numRows):
            mat.append("")

        n = 0
        step = 1

        for c in s:
            mat[n] += c

            if n == 0:
                step = 1
            elif n == numRows - 1:
                step = -1

            n += step

        return "".join(mat)


if __name__ == "__main__":
    Test = namedtuple("Test", "args expected")

    tests = [
        Test(("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR"),
        Test(("PAYPALISHIRING", 4), "PINALSIGYAHRPI"),
        Test(("PAYPALISHIRING", 1), "PAYPALISHIRING"),
    ]

    s = Solution()

    for t in tests:
        assert (s.convert(*t.args) == t.expected)
