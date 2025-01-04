//
// Created by FUGUO on 2024/12/29.
//
#include<iostream>
using namespace std;


typedef enum { OK, ERROR} status;

class BiTree {
private:
    struct BiNode {
        char data;
        BiNode * l_child, * r_chlid;
        BiNode(char data) : data(data),l_child(nullptr),r_chlid(nullptr) {};
    };
    BiNode * root;
    BiNode * createBiTree(const string pre_input,int &index);
    void deleteBiTree(BiNode * node);

public:
    BiTree(const string pre_input);
    ~BiTree();
    status Visited();
    BiNode * getroot() const;
    void PreOrder(BiNode * node);
    void InOrder(BiNode * node);
    void PostOrder(BiNode * node);
};

BiTree::BiTree(const string pre_input) {
    int index=0;
    root = createBiTree(pre_input,index);
}

BiTree::~BiTree() {
    deleteBiTree(root);
}

void BiTree::deleteBiTree(BiTree::BiNode *node) {
    if(node == nullptr) return;
    deleteBiTree(node->r_chlid);
    deleteBiTree(node->l_child);
    delete node;
}

BiTree::BiNode * BiTree::getroot() const {
    return root;
}

BiTree::BiNode * BiTree::createBiTree(const std::string pre_input, int &index) {
    if(index>=pre_input.size()||pre_input[index]=='*'||pre_input[index]=='#') {
        index++;
        return NULL;
    }
    BiNode* newroot = new BiNode(pre_input[index++]);
    newroot->l_child = createBiTree(pre_input, index);
    newroot->r_chlid = createBiTree(pre_input, index);
    return newroot;
}

void BiTree::PreOrder(BiNode * node) {
    if(node == nullptr) return;
    cout << node->data;
    PreOrder(node->l_child);
    PreOrder(node->r_chlid);
}

void BiTree::InOrder(BiNode * node) {
    if(node == nullptr) return;
    InOrder(node->l_child);
    cout << node->data;
    InOrder(node->r_chlid);
}

void BiTree::PostOrder(BiNode *node) {
    if(node== nullptr) return;
    PostOrder(node->l_child);
    PostOrder(node->r_chlid);
    cout << node->data;
}

void to_forward(string in, string post) {
    if(in.size()>0) {
        char ch = post[post.size()-1];
        cout << ch;
        int k = in.find(ch);
        to_forward(in.substr(0,k), post.substr(0,k));
        to_forward(in.substr(k+1),post.substr(k,post.size()-k-1));
    }
}

int main() {
    string input;
    cin >> input;
    BiTree BT(input);
    cout << endl;
    return 0;
}