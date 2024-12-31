// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476069
// Created by FUGUO on 2024/12/31.
//
#include<iostream>
#include<cstdio>
using namespace std;

struct node {
    char data;
    int left,right;
}tree1[30],tree2[30];

void check(int l_index, int r_index) {
//    if(tree1[l_index].data!=tree2[l_index].data) cout << "No." <<endl, exit(-1);
    int left1 = tree1[l_index].left;
    int right1 = tree1[l_index].right;
    int left2 = tree2[r_index].left;
    int right2 = tree2[r_index].right;
    if(left1==-1&&right1==-1&&right2==-1&&left2==-1) return;
    else if (left1 == -1 && right1 != -1 && left2 == -1 && right2 != -1) {
        if ( tree1[right1].data == tree2[right2].data) {
            check(right1, right2);
            return;
        }
        else cout << "No." << endl, exit(1);
    } else if (left1 == -1 && right1 != -1 && left2 != -1 && right2 == -1) {
        if ( tree1[right1].data == tree2[left2].data) {
            check(right1, left2);
            return;
        }
        else cout << "No." << endl, exit(1);
    } else if (left1 != -1 && right1 == -1 && left2 != -1 && right2 == -1) {
        if (tree1[left1].data == tree2[left2].data) {
            check(left1, left2);
            return;
        }
        else cout << "No." << endl, exit(1);
    } else if (left1 != -1 && right1 == -1 && left2 == -1 && right2 != -1) {
        if (tree1[left1].data == tree2[right2].data) {
            check(left1, right2);
            return;
        }
        else cout << "No." << endl, exit(1);
    } else if (left1 != -1 && right1 == -1 && left2 != -1 && right2 != -1) {
        cout << "No." << endl, exit(2);
    } else if (left1 == -1 && right1!= -1 && left2 != -1 && right2 != -1) {
        cout << "No." << endl, exit(2);
    } else if (left2 != -1 && right2 == -1 && left1 != -1 && right1 != -1) {
        cout << "No." << endl, exit(2);
    } else if (left2 == -1 && right2!= -1 && left1 != -1 && right1 != -1) {
        cout << "No." << endl, exit(2);
    } else if (left2 != -1 && right2 != -1 && left1 != -1 && right1 != -1) {
        if (tree1[left1].data == tree2[left2].data && tree1[right1].data == tree2[right2].data) {
            check(left1,left2);
            check(right1,right2);
            return;
        } else if (tree1[left1].data==tree2[right2].data && tree1[right1].data == tree2[left2].data) {
            check(left1,right2);
            check(right1,left2);
            return;
        }else {
            cout << "No." << endl;
            exit(3);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int root1,root2;
    for(int i=0;i<n;i++) {
        scanf(" %c %c %c",&tree1[i].data,&tree1[i].left,&tree1[i].right);
        if(tree1[i].data=='A') root1 =i;
        if( tree1[i].left == '-') tree1[i].left=-1;
        else tree1[i].left -= '0';
        if( tree1[i].right == '-') tree1[i].right=-1;
        else tree1[i].right -= '0';
    }
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf(" %c %c %c",&tree2[i].data,&tree2[i].left,&tree2[i].right);
        if(tree2[i].data == 'A') root2 = i;
        if( tree2[i].left == '-') tree2[i].left=-1;
        else tree2[i].left -= '0';
        if( tree2[i].right == '-') tree2[i].right=-1;
        else tree2[i].right -= '0';
    }
    check(root1,root2);
    cout << "Yes." << endl;
    return 0;
}
