#ifndef __TREE_UTILS_H__
#define __TREE_UTILS_H__

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void BFS(TreeNode *root);
void inorder(TreeNode *root);
void preorder(TreeNode *root);
void postorder(TreeNode *root);
void printBT(const TreeNode* node);
TreeNode* build_tree(std::vector<std::string> &arr);

#endif /*__TREE_UTILS_H__*/
