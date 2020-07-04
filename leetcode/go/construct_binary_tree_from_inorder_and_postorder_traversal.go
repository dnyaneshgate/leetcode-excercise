/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * Return the following binary tree:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 */

package main

func buildTreeUtil(inorder []int, postorder []int, index *int) *TreeNode {
	if len(inorder) == 0 {
		(*index)++
		return nil
	}

	root := &TreeNode{Val: postorder[*index]}

	find := func(arr []int, key int) int {
		for i := range arr {
			if arr[i] == key {
				return i
			}
		}
		return -1
	}

	inoIndex := find(inorder, postorder[*index])

	(*index)--
	root.Right = buildTreeUtil(inorder[inoIndex+1:], postorder, index)
	(*index)--
	root.Left = buildTreeUtil(inorder[:inoIndex], postorder, index)

	return root
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	index := len(postorder) - 1
	return buildTreeUtil(inorder, postorder, &index)
}

func main() {
	tests := []struct {
		inorder   []int
		postorder []int
	}{
		{
			[]int{},
			[]int{},
		},
		{
			[]int{9},
			[]int{9},
		},
		{
			[]int{9, 3, 15, 20, 7},
			[]int{9, 15, 7, 20, 3},
		},
		{
			[]int{15, 9, 3, 20, 7},
			[]int{15, 9, 7, 20, 3},
		},
	}

	for _, t := range tests {
		root := buildTree(t.inorder, t.postorder)
		PrintTree(root)
	}
}
