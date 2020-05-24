

from typing import List
from queue import Queue

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def BuildTree(arr: List[str]) -> TreeNode:
    q = Queue()

    v = int(arr[0])
    root = TreeNode(val=v)

    q.put(root)

    for i in range(1, len(arr), 2):
        node: TreeNode = q.get()

        if arr[i] != "null":
            v = int(arr[i])
            node.left = TreeNode(val=v)
            q.put(node.left)

        if i + 1 < len(arr) and arr[i + 1] != "null":
            v = int(arr[i+1])
            node.right = TreeNode(val=v)
            q.put(node.right)

    return root


def _printTreeUtil(prefix: str, root: TreeNode, level: int, isleft: bool):
    if root is None:
        return

    s: str = ""

    if level != 0:
        if isleft:
            s = prefix + "├──"
            prefix += "│   "
        else:
            s = prefix + "└──"
            prefix += "    "

    print("{}{}".format(s, root.val))

    if root.left is None and root.right is None:
        return

    _printTreeUtil(prefix, root.left, level + 1, True)
    _printTreeUtil(prefix, root.right, level+1, False)


def PrintTree(root: TreeNode):
    _printTreeUtil("", root, 0, False)


if __name__ == "__main__":
    arr = ["-10", "9", "20", "null", "null", "15", "7"]
    root = BuildTree(arr)
    PrintTree(root)
