/*
 * A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.
 *
 * Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.
 *
 * You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
 *
 * BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
 * BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
 * Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.
 *
 * For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 * Input: mat = [[0,0],[1,1]]
 * Output: 0
 *
 * Example 2:
 * Input: mat = [[0,0],[0,1]]
 * Output: 1
 *
 * Example 3:
 * Input: mat = [[0,0],[0,0]]
 * Output: -1
 *
 * Example 4:
 * Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
 * Output: 1
 *
 *
 * Constraints:
 *
 * rows == mat.length
 * cols == mat[i].length
 * 1 <= rows, cols <= 100
 * mat[i][j] is either 0 or 1.
 * mat[i] is sorted in a non-decreasing way.
 */

package main

import "fmt"

/*
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * type BinaryMatrix struct {
 *     Get(int, int) int
 *     Dimensions() []int
 * }
 */

// BinaryMatrix ...
type BinaryMatrix struct {
	mat [][]int
}

// Get ...
func (bm *BinaryMatrix) Get(x, y int) int {
	return bm.mat[x][y]
}

// Dimensions ...
func (bm *BinaryMatrix) Dimensions() []int {
	return []int{len(bm.mat), len(bm.mat[0])}
}

func leftMostColumnWithOne(binaryMatrix BinaryMatrix) int {
	dim := binaryMatrix.Dimensions()
	rows := dim[0]
	cols := dim[1]
	ret := -1

	for i, j := 0, cols-1; i < rows && j >= 0; {
		if binaryMatrix.Get(i, j) == 0 {
			i++
		} else {
			ret = j
			j--
		}
	}

	return ret
}

func main() {

	tests := []struct {
		mat      [][]int
		expected int
	}{
		{
			[][]int{
				[]int{0, 0, 0, 1},
				[]int{0, 0, 1, 1},
				[]int{0, 1, 1, 1},
			},
			1,
		},
		{
			[][]int{
				[]int{0, 0},
				[]int{1, 1},
			},
			0,
		},
		{
			[][]int{
				[]int{0, 0},
				[]int{0, 1},
			},
			1,
		},
		{
			[][]int{
				[]int{0, 0},
				[]int{0, 0},
			},
			-1,
		},
	}

	for _, t := range tests {
		bm := BinaryMatrix{mat: t.mat}
		fmt.Println("expected:", t.expected, "result:", leftMostColumnWithOne(bm))
	}

}
