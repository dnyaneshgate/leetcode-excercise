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

int pathMax(TreeNode *root) {
    if(!root)
        return 0;
    if(!root->left && !root->right) {
        // cout << "pathMax(" << root->val << ") = 0" << endl;
        return 0;
    }

    int ret = 1 + max(pathMax(root->left), pathMax(root->right));
    // cout << "pathMax(" << root->val << ") = " << ret << endl;
    return ret;
}

int diameterOfBinaryTree(TreeNode *root, int &diameter) {
    if(!root)
        return 0;
    if(!root->left && !root->right) {
        cout << "diameterOfBinaryTree(" << root->val << ") = 0, " << diameter << endl;
        return 0;
    }

    int leftMax = diameterOfBinaryTree(root->left, diameter);
    int rightMax = diameterOfBinaryTree(root->right, diameter);
    int ret = 1 + max(leftMax, rightMax);
    int rootMax = ((root->left) ? leftMax + 1 : 0) + ((root->right) ? rightMax + 1 : 0);

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
        { {"1","2","N","3","4","5","N","6"}, 4 },
        { {"1","2"}, 1 },
        { {"1"}, 0 },
    };

    for(auto &t: tests) {
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
