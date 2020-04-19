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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void BFS(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();

        if(!p) {
            cout << "N" << " ";
            continue;
        }

        cout << p->val << " ";

        q.push(p->left);
        q.push(p->right);
    }

    cout << endl;
}

void inorder_rec(TreeNode *root) {
    if(!root)
        return;

    inorder_rec(root->left);
    cout << root->val << " ";
    inorder_rec(root->right);
}

void inorder(TreeNode *root) {
    cout << "inorder = { ";
    inorder_rec(root);
    cout << "}" << endl;
}

void preorder_rec(TreeNode *root) {
    if(!root)
        return;

    cout << root->val << " ";
    preorder_rec(root->left);
    preorder_rec(root->right);
}

void preorder(TreeNode *root) {
    cout << "preorder = { ";
    preorder_rec(root);
    cout << "}" << endl;
}

void postorder_rec(TreeNode *root) {
    if(!root)
        return;

    postorder_rec(root->left);
    postorder_rec(root->right);
    cout << root->val << " ";
}

void postorder(TreeNode *root) {
    cout << "postorder = { ";
    postorder_rec(root);
    cout << "}" << endl;
}

TreeNode* build_tree(vector<string> &arr) {
    if(arr.size() == 0) {
        return nullptr;
    }
    queue<TreeNode*> q;
    TreeNode *root = new TreeNode(stoi(arr[0]));
    q.push(root);

    for(int i=0; i < arr.size()/2; ++i) {
        TreeNode *p = q.front();
        q.pop();

        int left  = 2*i + 1;
        int right = 2*i + 2;

        p->left  = (arr[left]  == "N") ? nullptr : new TreeNode(stoi(arr[left]));
        p->right = (arr[right] == "N") ? nullptr : new TreeNode(stoi(arr[right]));

        if(p->left)
            q.push(p->left);

        if(p->right)
            q.push(p->right);
    }

    return root;
}

int diameterOfBinaryTree(TreeNode* root) {

}

int main() {
    struct test {
        vector<string> arr;
        int expected;
    };

    vector<test> tests = {
        { {"1", "2", "N", "3", "4"}, 2 },
    };

    for(auto &t: tests) {
        TreeNode *root = build_tree(t.arr);
        BFS(root);
        inorder(root);
        preorder(root);
        postorder(root);
    }
    return 0;
}
