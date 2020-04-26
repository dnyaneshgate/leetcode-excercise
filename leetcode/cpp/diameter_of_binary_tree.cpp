/*
 * Given a binary tree, you need to compute the length of the diameter of the tree.
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
 * This path may or may not pass through the root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Note: The length of path between two nodes is represented by the number of edges between them.
 */

#include <bits/stdc++.h>

#include "tree_utils.h"

using namespace std;

int pathMax(TreeNode *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right) {
        // cout << "pathMax(" << root->val << ") = 0" << endl;
        return 0;
    }

    int ret = 1 + max(pathMax(root->left), pathMax(root->right));
    // cout << "pathMax(" << root->val << ") = " << ret << endl;
    return ret;
}

int diameterOfBinaryTree(TreeNode *root, int &diameter) {
    if (!root)
        return 0;
    if (!root->left && !root->right) {
        cout << "diameterOfBinaryTree(" << root->val << ") = 0, " << diameter << endl;
        return 0;
    }

    int leftMax  = diameterOfBinaryTree(root->left, diameter);
    int rightMax = diameterOfBinaryTree(root->right, diameter);
    int ret      = 1 + max(leftMax, rightMax);
    int rootMax  = ((root->left) ? leftMax + 1 : 0) + ((root->right) ? rightMax + 1 : 0);

    diameter = max({diameter, ret, rootMax});

    cout << "diameterOfBinaryTree(" << root->val << ") = " << ret << ", " << diameter << endl;

    return ret;
}

int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    diameterOfBinaryTree(root, diameter);
    return diameter;
}

int main() {
    struct test {
        vector<string> arr;
        int expected;
    };

    vector<test> tests = {
        {{"1", "2", "N", "3", "4", "5", "N", "6"}, 4},
        {{"1", "2"}, 1},
        {{"1"}, 0},
    };

    for (auto &t : tests) {
        TreeNode *root = build_tree(t.arr);
        // printBT(root);
        // BFS(root);
        // inorder(root);
        // preorder(root);
        // postorder(root);
        int ret = diameterOfBinaryTree(root);
        cout << ret << endl;
        assert(ret == t.expected);
    }
    return 0;
}
