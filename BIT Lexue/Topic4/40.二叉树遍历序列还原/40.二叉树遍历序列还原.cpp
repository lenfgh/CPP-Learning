// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476060
// Created by FUGUO on 2024/12/19.
//
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(const string& inorder, int inStart, int inEnd, const string& postorder, int postStart, int postEnd, unordered_map<char, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    char rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

TreeNode* buildTree(const string& inorder, const string& postorder) {
    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;
    TreeNode* root = buildTree(inorder, postorder);
    printLevelOrder(root);
    return 0;
}
