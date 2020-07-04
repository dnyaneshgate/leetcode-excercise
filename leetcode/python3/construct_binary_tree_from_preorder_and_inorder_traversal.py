"""
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
    def __bisearch(self, arr: List[int], key: int) -> int:
        if not arr:
            return -1

        mid: int = len(arr) // 2
        if arr[mid] == key:
            return mid
        if key < arr[mid]:
            return self.__bisearch(arr[:mid], key)
        return self.__bisearch(arr[mid + 1:], key)

    def __buildTree(self, preorder: List[int], inorder: List[int], index: int = 0) -> (TreeNode, int):
        print("preorder:", preorder, "  inorder:", inorder, "   index:", index)
        if not inorder:
            return None, index - 1

        root: TreeNode = TreeNode(val=preorder[index])
        ino_index = inorder.index(preorder[index])

        print("index:", index, "root:", root.val, "ino_index:", ino_index)

        root.left, index = self.__buildTree(preorder, inorder[:ino_index], index + 1)
        root.right, index = self.__buildTree(preorder, inorder[ino_index + 1:], index + 1)

        return root, index

    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        root, _ = self.__buildTree(preorder, inorder)
        return root


class TestSolution(unittest.TestCase):
    def test_buildTree(self):
        tests = [
            ([3, 9, 20, 15, 7], [9, 3, 15, 20, 7]),
            ([9], [9]),
            ([3, 9, 15, 20, 7], [15, 9, 3, 20, 7]),
        ]

        for t in tests:
            root = Solution().buildTree(*t)
            PrintTree(root)


if __name__ == "__main__":
    unittest.main()
