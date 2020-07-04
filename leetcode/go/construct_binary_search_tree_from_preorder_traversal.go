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

func bstFromPreorder(preorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	root := NewTreeNode(preorder[0])
	index := -1
	for i := 1; i < len(preorder); i++ {
		if preorder[i] > preorder[0] {
			index = i
			break
		}
	}

	if index == -1 {
		root.Left = bstFromPreorder(preorder[1:])
	} else {
		root.Left = bstFromPreorder(preorder[1:index])
		root.Right = bstFromPreorder(preorder[index:])
	}

	return root
}

func main() {
	tests := [][]int{
		{8, 5, 1, 7, 10, 9, 12},
		{8, 5, 1, 7, 10, 12},
		{8, 5, 1, 7, 10, 9},
	}

	for _, t := range tests {
		root := bstFromPreorder(t)
		PrintTree(root)
	}
}
