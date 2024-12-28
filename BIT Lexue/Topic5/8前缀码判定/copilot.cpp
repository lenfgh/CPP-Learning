// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=476068
// Created by FUGUO on 2024/12/25.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[2];
    TrieNode() : isEnd(false) {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    bool insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - '0';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            if (node->isEnd) {
                return false; // Current word is a prefix of an existing word
            }
        }
        node->isEnd = true;
        for (int i = 0; i < 2; ++i) {
            if (node->children[i]) {
                return false; // An existing word is a prefix of the current word
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    int n;
    cin >> n;
    Trie trie;
    bool yes = true;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        if (yes && !trie.insert(input)) {
            yes = false;
            cout << input << endl;
        }
    }
    if (yes) cout << "YES" << endl;
    return 0;
}
