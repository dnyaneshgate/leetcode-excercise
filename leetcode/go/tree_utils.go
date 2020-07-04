package main

import (
	"fmt"
	"queue"
	"strconv"
)

// TreeNode ...
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// NewTreeNode ...
func NewTreeNode(val int) *TreeNode {
	return &TreeNode{Val: val}
}

// BuildTree ...
func BuildTree(vec []string) *TreeNode {
	q := queue.NewArrayQueue()

	var v int

	v, _ = strconv.Atoi(vec[0])
	root := &TreeNode{Val: v}
	q.Push(root)

	for i := 1; i < len(vec); i += 2 {
		node := q.Front().(*TreeNode)
		q.Pop()

		if vec[i] != "null" {
			v, _ = strconv.Atoi(vec[i])
			node.Left = &TreeNode{Val: v}
			q.Push(node.Left)
		}

		if (i+1 < len(vec)) && (vec[i+1] != "null") {
			v, _ = strconv.Atoi(vec[i+1])
			node.Right = &TreeNode{Val: v}
			q.Push(node.Right)
		}
	}

	return root
}

func printTreeUtil(prefix string, root *TreeNode, level int, leftchild bool) {
	if root == nil {
		return
	}

	var s string

	if level != 0 {
		if leftchild {
			s = prefix + "├──"
			prefix += "│   "
		} else {
			s = prefix + "└──"
			prefix += "    "
		}
	}

	fmt.Printf("%v%v\n", s, root.Val)

	if root.Left == nil && root.Right == nil {
		return
	}

	printTreeUtil(prefix, root.Left, level+1, true)
	printTreeUtil(prefix, root.Right, level+1, false)
}

// PrintTree ...
func PrintTree(root *TreeNode) {
	printTreeUtil("", root, 0, false)
}
