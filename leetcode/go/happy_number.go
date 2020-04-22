/**
 * Write an algorithm to determine if a number n is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer,
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Return True if n is a happy number, and False if not.
 *
 * Example:
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */

package main

import "fmt"

var mp = map[int]int{}

func isHappyRec(num int) bool {
	if num == 1 {
		return true
	}

	if _, ok := mp[num]; ok {
		return false
	}

	mp[num] = 1

	var n int
	var temp int

	for num > 0 {
		temp = num % 10
		n += temp * temp
		num /= 10
	}

	return isHappyRec(n)
}

func isHappy2(num int) bool {
	mp = map[int]int{}
	return isHappyRec(num)
}

func calcAquareSum(num int) int {
	var n int
	var temp int

	for num > 0 {
		temp = num % 10
		n += temp * temp
		num /= 10
	}

	return n
}

func isHappy(num int) bool {
	current := calcAquareSum(num)
	next := calcAquareSum(current)
	next = calcAquareSum(next)

	for current != next {
		current = calcAquareSum(current)
		next = calcAquareSum(calcAquareSum(next))
	}

	return 1 == next
}

func main() {
	tests := []struct {
		num      int
		expected bool
	}{
		{19, true},
		{17, false},
		{10, true},
	}

	for indx, t := range tests {
		if isHappy(t.num) != t.expected {
			panic(fmt.Sprintf("Test %v failed", indx))
		}
	}
}
