"""
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
"""

import unittest
from typing import List
from tree_utils import TreeNode, PrintTree


class Solution:
    def __buildTree(self, inorder: List[int], postorder: List[int], index: int = -1) -> (TreeNode, int):
        print("postorder:", postorder, "  inorder:", inorder, "   index:", index)
        if not inorder:
            return None, index + 1

        root: TreeNode = TreeNode(val=postorder[index])
        ino_index = inorder.index(postorder[index])

        print("index:", index, "root:", root.val, "ino_index:", ino_index)

        root.right, index = self.__buildTree(inorder[ino_index + 1:], postorder, index - 1)
        root.left, index = self.__buildTree(inorder[:ino_index], postorder, index - 1)

        return root, index

    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        root, _ = self.__buildTree(inorder, postorder)
        return root


class TestSolution(unittest.TestCase):
    def test_buildTree(self):
        tests = [
            ([9, 3, 15, 20, 7], [9, 15, 7, 20, 3]),
            ([9], [9]),
            ([15, 9, 3, 20, 7], [15, 9, 7, 20, 3]),
        ]

        for t in tests:
            root = Solution().buildTree(*t)
            PrintTree(root)


if __name__ == "__main__":
    unittest.main()
