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

package main

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	mat := []string{}
	for i := 0; i < numRows; i++ {
		mat = append(mat, "")
	}

	n := 0
	step := 1
	for _, c := range s {
		mat[n] += string(c)

		switch n {
		case 0:
			step = 1
		case numRows - 1:
			step = -1
		}

		n += step
	}

	var ret string
	for i := 0; i < len(mat); i++ {
		ret += mat[i]
	}

	return ret
}

func main() {
	tests := []struct {
		str      string
		n        int
		expected string
	}{
		{"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
		{"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
		{"AB", 1, "AB"},
	}

	assert := func(ok bool, msg string) {
		if !ok {
			panic(msg)
		}
	}

	for _, t := range tests {
		assert(convert(t.str, t.n) == t.expected, "Failed")
	}
}
