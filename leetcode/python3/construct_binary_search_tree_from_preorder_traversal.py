"""
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
"""

from typing import List
from tree_utils import TreeNode, BuildTree, PrintTree


class Solution:
    def buildTreeUtils(self, preorder: List[int]) -> TreeNode:
        if not preorder:
            return None

        root = TreeNode(val=preorder[0])
        index = -1

        for i in range(1, len(preorder)):
            if preorder[i] > preorder[0]:
                index = i
                break

        if index == -1:
            root.left = self.buildTreeUtils(preorder[1:])
        else:
            root.left = self.buildTreeUtils(preorder[1:index])
            root.right = self.buildTreeUtils(preorder[index:])

        return root

    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        return self.buildTreeUtils(preorder)


if __name__ == "__main__":
    s = Solution()
    root = s.bstFromPreorder([8, 5, 1, 7, 10, 9, 12])
    PrintTree(root)

    root = s.bstFromPreorder([8, 5, 1, 7, 10, 12])
    PrintTree(root)

    root = s.bstFromPreorder([8, 5, 1, 7, 10, 9])
    PrintTree(root)
