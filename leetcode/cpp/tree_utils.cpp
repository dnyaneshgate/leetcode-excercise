#include <iostream>
#include <vector>
#include <queue>

#include "tree_utils.h"

using namespace std;

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

/*
 * https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
 */
void printBT(const std::string& prefix, const TreeNode* node, bool isLeft) {
    if( node != nullptr ) {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << node->val << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const TreeNode* node) {
    printBT("", node, false);
}

TreeNode* build_tree(vector<string> &arr) {
    if(arr.size() == 0) {
        return nullptr;
    }
    queue<TreeNode*> q;
    TreeNode *root = new TreeNode(stoi(arr[0]));
    q.push(root);

    for(int i=1; i < arr.size(); i+=2) {
        TreeNode *p = q.front();
        q.pop();

        p->left  = (arr[i]  == "N") ? nullptr : new TreeNode(stoi(arr[i]));

        if(i < arr.size()-1) {
            p->right = (arr[i+1] == "N") ? nullptr : new TreeNode(stoi(arr[i+1]));
        }

        if(p->left)
            q.push(p->left);

        if(p->right)
            q.push(p->right);
    }

    return root;
}
