/*
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the root.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 *
 *        1
 *       / \
 *      2   3
 *
 * Output: 6
 * Example 2:
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 *    -10
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * Output: 42
 */

package main

import (
	"fmt"
	"math"
)

/*
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// IntArr ..
type IntArr []int

func (arr *IntArr) max() int {
	ret := math.MinInt64
	for i := 0; i < len(*arr); i++ {
		ret = max(ret, (*arr)[i])
	}
	return ret
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func dfs(root *TreeNode, sum *int) int {
	if root == nil {
		return math.MinInt64
	}

	if root.Left == nil && root.Right == nil {
		*sum = max(*sum, root.Val)
		return root.Val
	}

	var ll, rr, llrr int

	ll = dfs(root.Left, sum)
	rr = dfs(root.Right, sum)

	llrr = root.Val
	if root.Left != nil {
		llrr += ll
	}
	if root.Right != nil {
		llrr += rr
	}

	// arr := IntArr{*sum, ll, rr, llrr, root.Val}
	// *sum = arr.max()
	*sum = max(*sum, max(ll, max(rr, max(root.Val, llrr))))
	// fmt.Println(root.Val, ll, rr, llrr, *sum)

	return max(root.Val, root.Val+max(ll, rr))
}

func maxPathSum(root *TreeNode) int {
	sum := math.MinInt64
	sum = max(sum, dfs(root, &sum))
	return sum
}

/*
 * var sum int
 *
 * func maxPathSum(root *TreeNode) int {
 * 	sum = math.MinInt64
 * 	helper(root)
 * 	return sum
 * }
 *
 * func helper(root *TreeNode) int {
 * 	if root == nil {
 * 		return 0
 * 	}
 *
 * 	left := max(0, helper(root.Left))
 * 	right := max(0, helper(root.Right))
 *
 * 	sum = max(sum, left+right+root.Val)
 *
 * 	return root.Val + max(left, right)
 * }
 */

func main() {
	tests := []struct {
		arr      []string
		expected int
	}{
		{
			[]string{"1", "2", "3"},
			6,
		},
		{
			[]string{"-10", "9", "20", "null", "null", "15", "7"},
			42,
		},
		{
			[]string{"-3"},
			-3,
		},
		{
			[]string{"1", "2"},
			3,
		},
		{
			[]string{"-2", "-1"},
			-1,
		},
		{
			[]string{"1", "-2", "3"},
			4,
		},
	}

	for _, t := range tests {
		root := BuildTree(t.arr)
		// PrintTree(root)
		fmt.Println("expected:", t.expected, "result:", maxPathSum(root))
	}
}
