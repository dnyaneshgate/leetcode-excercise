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

#include <bits/stdc++.h>

#include "tree_utils.h"

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int bisearch_rec(vector<int> &arr, int target, int low, int high) {
    if (low > high) {
        return -1;
    }

    if (low == high && arr[low] == target) {
        return low;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (target < arr[mid]) {
        return bisearch_rec(arr, target, low, mid - 1);
    }

    return bisearch_rec(arr, target, mid + 1, high);
}

int bisearch(vector<int> &arr, int target) {
    return bisearch_rec(arr, target, 0, arr.size() - 1);
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int &index, int ino_start, int ino_end) {
    if (index >= preorder.size()) {
        return nullptr;
    }

    if (ino_start > ino_end) {
        --index;
        return nullptr;
    }

    int ino_index = bisearch_rec(inorder, preorder[index], ino_start, ino_end);
    if (ino_index == -1) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[index]);

    root->left  = buildTree(inorder, preorder, ++index, ino_start, ino_index - 1);
    root->right = buildTree(inorder, preorder, ++index, ino_index + 1, ino_end);

    return root;
}

TreeNode *bstFromInorder(vector<int> &inorder, int low, int high) {
    if (low > high) {
        return nullptr;
    }

    int mid = (low + high) / 2;

    TreeNode *root = new TreeNode(inorder[mid]);

    root->left  = bstFromInorder(inorder, low, mid - 1);
    root->right = bstFromInorder(inorder, mid + 1, high);

    return root;
}

TreeNode *bstFromInorder(vector<int> &inorder) {
    return bstFromInorder(inorder, 0, inorder.size() - 1);
}

TreeNode *bstFromPreorder(vector<int> &preorder) {
    vector<int> inorder(preorder);
    sort(inorder.begin(), inorder.end());
    int index = 0;
    return buildTree(inorder, preorder, index, 0, inorder.size() - 1);
    // return bstFromInorder(inorder);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root       = bstFromPreorder(preorder);
    printBT(root);
    return 0;
}
