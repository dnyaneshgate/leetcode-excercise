/*
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 *
 * A subsequence of a string is a new string generated from the original string with some characters(can be none)
 * deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not).
 * A common subsequence of two strings is a subsequence that is common to both strings.
 *
 * If there is no common subsequence, return 0.
 *
 * Example 1:
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 * Example 2:
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 * Example 3:
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 *
 * Constraints:
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 */

package main

import "fmt"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func longestCommonSubsequence(text1 string, text2 string) int {
	var rows, cols = len(text1) + 1, len(text2) + 1
	var lookup = make([][]int, rows)
	for i := range lookup {
		lookup[i] = make([]int, cols)
	}

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if i == 0 || j == 0 {
				lookup[i][j] = 0
			} else if text1[i-1] == text2[j-1] {
				lookup[i][j] = 1 + lookup[i-1][j-1]
			} else {
				lookup[i][j] = max(lookup[i][j-1], max(lookup[i-1][j-1], lookup[i-1][j]))
			}
		}
	}
	return lookup[rows-1][cols-1]
}

func main() {
	tests := []struct {
		text1    string
		text2    string
		expected int
	}{
		{
			"abcde",
			"ace",
			3,
		},
		{
			"abc",
			"abc",
			3,
		},
		{
			"abc",
			"def",
			0,
		},
	}

	for _, t := range tests {
		fmt.Println("expected:", t.expected, "output:", longestCommonSubsequence(t.text1, t.text2))
	}
}
