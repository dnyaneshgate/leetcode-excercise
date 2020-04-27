/*
 * Return the root node of a binary search tree that matches the given preorder traversal.
 *
 * (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
 *
 *
 *
 * Example 1:
 *
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 *
 *
 *
 * Note:
 *
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
 */

package main

// TreeNode ...
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func newTreeNode(val int) *TreeNode {
	return &TreeNode{Val: val}
}

func bsUtils(preorder []int, low, high int) *TreeNode {
	if low > high {
		return nil
	}

	root := newTreeNode(preorder[low])
	index := -1
	for i := low + 1; i <= high; i++ {
		if preorder[low] < preorder[i] {
			index = i
			break
		}
	}

	if index == -1 {
		root.Left = bsUtils(preorder, low+1, high)
		return root
	}

	root.Left = bsUtils(preorder, low+1, index-1)
	root.Right = bsUtils(preorder, index, high)

	return root
}

func bstFromPreorder(preorder []int) *TreeNode {
	return bsUtils(preorder, 0, len(preorder)-1)
}

func main() {

}
