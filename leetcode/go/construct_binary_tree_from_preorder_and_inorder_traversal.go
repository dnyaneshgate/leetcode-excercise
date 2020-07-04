/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 */

package main

func buildTreeUtil(preorder []int, inorder []int, index *int) *TreeNode {
	if len(inorder) == 0 {
		(*index)--
		return nil
	}

	root := &TreeNode{Val: preorder[*index]}

	find := func(arr []int, key int) int {
		for i := range arr {
			if arr[i] == key {
				return i
			}
		}
		return -1
	}

	inoIndex := find(inorder, preorder[*index])

	(*index)++
	root.Left = buildTreeUtil(preorder, inorder[:inoIndex], index)

	(*index)++
	root.Right = buildTreeUtil(preorder, inorder[inoIndex+1:], index)

	return root
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	index := 0
	return buildTreeUtil(preorder, inorder, &index)
}

func main() {
	tests := []struct {
		preorder []int
		inorder  []int
	}{
		{[]int{9}, []int{9}},
		{[]int{3, 9, 20, 15, 7}, []int{9, 3, 15, 20, 7}},
		{[]int{3, 9, 15, 20, 7}, []int{15, 9, 3, 20, 7}},
	}

	for _, t := range tests {
		root := buildTree(t.preorder, t.inorder)
		PrintTree(root)
	}
}
