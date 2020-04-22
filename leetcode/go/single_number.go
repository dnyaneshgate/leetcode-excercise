/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * Example 1:
 *
 * Input: [2,2,1]
 * Output: 1
 * Example 2:
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 */

package main

import "fmt"

func singleNumber(nums []int) int {
	var ret = nums[0]

	for i := 1; i < len(nums); i++ {
		ret ^= nums[i]
	}

	return ret
}

func main() {
	tests := []struct {
		nums     []int
		expected int
	}{
		{[]int{2, 2, 1}, 1},
		{[]int{4, 1, 2, 1, 2}, 4},
	}

	for indx, t := range tests {
		if singleNumber(t.nums) != t.expected {
			panic(fmt.Sprintf("Test %v failed", indx))
		}
	}
}
