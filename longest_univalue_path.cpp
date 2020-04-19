/*
 * Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
 *
 * The length of path between two nodes is represented by the number of edges between them.
 *
 *
 *
 * Example 1:
 *
 * Input:
 *
 *               5
 *              / \
 *             4   5
 *            / \   \
 *           1   1   5
 * Output: 2
 *
 *
 *
 * Example 2:
 *
 * Input:
 *
 *               1
 *              / \
 *             4   5
 *            / \   \
 *           4   4   5
 * Output: 2
 *
 *
 *
 * Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
 */




#include <bits/stdc++.h>

#include "tree_utils.h"

using namespace std;

int longestUnivaluePath(TreeNode *root, int &maxUniquePath) {
    if(!root)
        return 0;
    if(!root->left && !root->right) {
        cout << "longestUnivaluePath(" << root->val << ") = 0, " << maxUniquePath << endl;
        return 0;
    }

    int leftMax = longestUnivaluePath(root->left, maxUniquePath);
    int rightMax = longestUnivaluePath(root->right, maxUniquePath);

    leftMax = (root->left && root->left->val == root->val) ? leftMax + 1 : 0;
    rightMax = (root->right && root->right->val == root->val) ? rightMax + 1 : 0;

    int ret = max(leftMax, rightMax);
    int rootMax = ((root->left) ? leftMax : 0) + ((root->right) ? rightMax : 0);

    maxUniquePath = max({maxUniquePath, ret, rootMax});

    cout << "longestUnivaluePath(" << root->val << ") = " << ret << ", " << maxUniquePath << endl;

    return ret;
}

int longestUnivaluePath(TreeNode *root) {
    int maxUniquePath = 0;
    longestUnivaluePath(root, maxUniquePath);
    return maxUniquePath;
}

int main() {
    struct test {
        vector<string> arr;
        int expected;
    };

    vector<test> tests = {
        {{"5","4","5","1","1","N","5"}, 2},
        {{"1","4","5","4","4","N","5"}, 2},
        {{"1","2","N","3","4","5","N","6"}, 0}
    };

    for(auto &t: tests) {
        TreeNode *root = build_tree(t.arr);
        // printBT(root);
        int ret = longestUnivaluePath(root);
        cout << ret << endl;
        assert(ret == t.expected);
    }
    return 0;
}
