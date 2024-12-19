// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476060
// Created by FUGUO on 2024/12/19.
//

#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(const string &s, int &index) {
    if (index >= s.size() || s[index] == '#') {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(s[index++]);
    root->left = createTree(s, index);
    root->right = createTree(s, index);
    return root;
}

void printIndented(TreeNode* root, int depth = 0) {
    if (!root) return;
    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << root->val << endl;
    printIndented(root->left, depth + 1);
    printIndented(root->right, depth + 1);
}

void preOrder(TreeNode* root) {
    if (!root) return;
    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val;
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val;
}

int countLeaves(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void swapChildren(TreeNode* root) {
    if (!root) return;
    swap(root->left, root->right);
    swapChildren(root->left);
    swapChildren(root->right);
}

int main() {
    string input;
    cin >> input;
    int index = 0;
    TreeNode* root = createTree(input, index);

    cout << "BiTree" << endl;
    printIndented(root);

    cout << "pre_sequence  : ";
    preOrder(root);
    cout << endl;

    cout << "in_sequence   : ";
    inOrder(root);
    cout << endl;

    cout << "post_sequence : ";
    postOrder(root);
    cout << endl;

    cout << "Number of leaf: " << countLeaves(root) << endl;

    swapChildren(root);

    cout << "BiTree swapped" << endl;
    printIndented(root);

    cout << "pre_sequence  : ";
    preOrder(root);
    cout << endl;

    cout << "in_sequence   : ";
    inOrder(root);
    cout << endl;

    cout << "post_sequence : ";
    postOrder(root);
    cout << endl;

    return 0;
}


