// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476051
// Created by FUGUO on 2024/12/17.
//

// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476051
// Created by FUGUO on 2024/12/17.
//

#include<iostream>
#include<cstdio>
using namespace std;


class Joseph {
private:
    struct node {
        int index;
        node * next;
        node * last;
        node(int x, node * p = NULL, node * q= NULL) : index(x),next(p),last(q) { }
    };
    node * head;

public:
    Joseph(int n);
    ~Joseph();
    void simulate(int n, int m, int k);
    int calculate();
    void printList();
};

Joseph::Joseph(int n) {
    node * p;
    node * temp;
    head = p = new node(0);
    for (int i=1;i<=n;i++) {
//        cout << "make" << i << endl;
        temp = p;
        p -> next = new node(i);
        p = p ->next;
        p -> last = temp;
    }
    p->next = head;
    head->last = p;
};


Joseph::~Joseph() {
    node * p;
    if(head == NULL) {
        return;
    } else {
        while (head->next!=head) {
            p = head->next;
            head -> next = p -> next;
            delete p;
        }
        delete head;
    }
};

int Joseph::calculate() {
    int i = 0;
    node * p;
    p = head;
    while(p->next!=head) {
//        cout << p->index<<endl;
        p = p->next;
        i++;
    }
//    cout << p->index;
    return i;
};// calculate the length of the Joseph

void Joseph::simulate(int n, int k, int m) {
//    cout << n << m << k << endl;
    if(k > n) {
        cout << "k should not bigger than n." << endl;
        return;
    }
    if(k*n*m==0) {
        cout << "n,m,k must bigger than 0." << endl;
        return;
    }
    int out1,out2;
    node * p1;
    node * p2;
    node * start;
    start = head;
    for (int i=1;i<=k;i++){
        start = start->next;
    }
    p1=p2=start;
    for (;head->next!=head;) {// for the special condition that there is only head left(kick out 2 at last)

        int tot=calculate();
//        cout << "tot:" << tot << endl;


        if(tot==1) {
            n= head->next->index;
            cout << n << ',';
            break;
        } // for the special condition that there is only one left(then kick out it)

//         cout << "Current list: ";
//         printList();

//        cout << "check 0" << endl;


        for ( int i=1;i<=m-1;i++){
            p1 = p1 -> last;
            if ( p1 == head ) {
                i--;
            }
        }

        for ( int i=1;i<=m-1;i++) {
            p2 = p2 -> next;
            if ( p2 == head ) {
                i--;
            }
        }


        out1 = p1 -> index;
        out2 = p2 -> index;

//        cout << "task" <<temp1->index << "and" << temp2->index<<endl;

        (p1 -> next) -> last = p1 -> last;
        (p1 -> last) -> next = p1 -> next;

        (p2 -> last) -> next = p2 -> next;
        (p2 -> next) -> last = p2 -> last;

//        temp1 = p1;
//        temp2 = p2;
//
//        delete temp1;
//        delete temp2;

        p1 = (p1->next)->last;
        p2 = (p2->last)->next;

//        cout << "Check the target";
//        cout << p1->index << "and"<< p2->index << endl;
//        cout << p1->last->index << "and" << p2->next->index ;
//        cout << temp1->last->index << "and" << temp2->next->index << endl;

        if (out1 == out2) {

            cout << out1 << ',';

        } else {
            // ! swap the order
            cout << out2 << '-' << out1 << ',';
        }


        if(p2 == head) {
            p2 = p2 -> next;
        }
        if( p1==head ) {
            p1 = p1 -> last;
        }

    }
    cout << endl;
}

void Joseph::printList() {
    node *p = head;
    do {
        cout << p->index << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
};// debug function;

int main() {
    int n,m,k;
    scanf("%d,%d,%d" , &n,&m,&k);

    Joseph h(n);
    h.simulate(n,m,k);

    return 0;

}