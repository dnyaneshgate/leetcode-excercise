/*
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the root.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 *
 *        1
 *       / \
 *      2   3
 *
 * Output: 6
 * Example 2:
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 *    -10
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * Output: 42
 */

/* ALTERNATE SOLUTIONS */

/*
 * class Solution {
 * public:
 *     int maxs=INT_MIN;
 *
 *     int huh(TreeNode* root)
 *     {
 *         if(root==NULL)
 *         return 0;
 *
 *         int left=huh(root->left);
 *         int right=huh(root->right);
 *
 *         int rt=root->val;
 *         int lrt=left+root->val;
 *         int rrt=right+root->val;
 *         int lrrt=left+right+root->val;
 *         maxs=max(rt,max(lrt,max(rrt,max(lrrt,maxs))));
 *         return max(rt,max(lrt,rrt));
 *
 *     }
 *
 *     int maxPathSum(TreeNode* root) {
 *         huh(root);
 *         return maxs;
 *     }
 * };
 */

/*
 * #pragma GCC optimize ("Ofast")
 * static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();
 *
 * class Solution {
 * public:
 *     int helper(TreeNode* root, int &maxsum) {
 *         if(!root) return 0;
 *         int l = helper(root->left, maxsum);
 *         int r = helper(root->right, maxsum);
 *
 *         if(l<0) l=0;
 *         if(r<0) r=0;
 *
 *         if (l + root->val + r >maxsum)
 *             maxsum = l + root->val + r;
 *
 *         if (l>r) return root->val + l;
 *         else return root->val + r;
 *     }
 *     int maxPathSum(TreeNode* root) {
 *         if(!root) return 0;
 *         int maxsum = root->val;
 *         helper(root, maxsum);
 *         return maxsum;
 *     }
 * };
 */

#include <bits/stdc++.h>

#include "tree_utils.h"

using namespace std;

int maxPathSum(TreeNode *root, int &sum) {
    if (!root)
        return 0;
    if (!root->left && !root->right) {
        sum = max(sum, root->val);
        return root->val;
    }

    int leftSum  = maxPathSum(root->left, sum);
    int rightSum = maxPathSum(root->right, sum);

    int ret     = max(root->val + max(leftSum, rightSum), root->val);
    int rootMax = root->val + leftSum + rightSum;

    sum = max({sum, ret, rootMax, root->val});

    return ret;
}

int maxPathSum(TreeNode *root) {
    int sum = INT_MIN;
    ;
    maxPathSum(root, sum);
    return sum;
}

int main() {
    struct test_t {
        vector<string> arr;
        int expected;
    };

    vector<test_t> tests = {
        {{"1", "2", "3"}, 6},
        {{"-10", "9", "20", "N", "N", "15", "7"}, 42},
        {{"1", "3"}, 4},
        {{"1"}, 1},
        {{"-3"}, -3},
        {{"2", "-1", "-2"}, 2},
        {{"9", "6", "-3", "N", "N", "-6", "2", "N", "N", "2", "N", "-6", "-6", "-6"}, 16},
    };

    for (auto &t : tests) {
        TreeNode *root = build_tree(t.arr);
        assert(maxPathSum(root) == t.expected);
    }
    return 0;
}
