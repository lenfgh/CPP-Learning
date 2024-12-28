// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=476067
// Created by FUGUO on 2024/12/25.
//
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int tree[1005];
int tot;
map<int,int> father1;

int main() {
    cin >> tot;

    for(int i=1; i<=tot; i++) {
        cin >> tree[i];
    }

    int node1,node2;
    cin >> node1 >> node2;
//    cout << "nodes are " << node1 << ' ' << node2 << endl;
    if(tree[node1]==0) {
        cout << "ERROR: T[" << node1 << "] is NULL" <<endl; return 1;
    }
    if(tree[node2]==0) {
        cout << "ERROR: T[" << node2 << "] is NULL" <<endl; return 1;
    }

    int f_node1 = node1;
    for(int i=0; f_node1 != 0;i++) {
//        cout << "f_node 1 is " << f_node1 << endl;
        if(tree[f_node1]!=0) father1[f_node1] = tree[f_node1];
        f_node1 = ceil(f_node1/2);
    }

    int f_node2 = node2;
    for(int i=0; f_node2 != 0;i++){
//        cout << "f_node2 is " << f_node2 << endl;
        if(tree[f_node2]!=0) {
            bool contain = father1.find(f_node2) != father1.end();
            if (contain) {
                cout << f_node2 << ' ' << father1[f_node2] << endl;
                break;
            }
        }
        f_node2 = floor(f_node2/2);
    }


    return 0;
}