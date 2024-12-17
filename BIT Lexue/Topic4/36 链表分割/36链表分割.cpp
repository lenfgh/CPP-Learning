// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=469053
// Created by FUGUO on 2024/12/17.
//

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

class List
{
    struct Node {
        int data;
        Node *next;
        Node()
        {
            data = -1;
            next = NULL;
        }
        Node(int x, Node *p=NULL)
        {
            data = x;
            next = p;
        }
    };
protected:
    Node * first;
public:
    List()
    {
        first = new Node;
    }
    ~List()
    {
        freeList();
    }
    void freeList();
    void append(const int num);
    void output();
    void split(List& A, List& B);
};

void List::freeList()
{
    Node * del;
    while ( first->next != NULL ) {
        del = first->next;
        first->next = del->next;
        delete del;
    }
}

void List::append(int num)
{
    Node *last = first;
    while ( last->next!=NULL ) {
        last = last->next;
    }
    last->next = new Node( num );
}

void List::output()
{
    Node *p = first->next;
    while ( p!=NULL ) {
        cout << p->data << ",";
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    List L, A, B;
    int num;
    cin >> num;
    while ( num != -1 ) {
        L.append(num);
        cin >> num;
    }
    cout << "L=";
    L.output();
    L.split(A, B);
    cout << "A=";
    A.output();
    cout << "B=";
    B.output();
    cout << "L=";
    L.output();
    L.~List();
    A.~List();
    B.~List();
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void List::split(List &A, List &B) {
    Node * p;
    p = first -> next;
    while(p->next!=NULL) {
        if (p->data % 2 == 1) {
            A.append(p->data);

        } else if (p->data %2 ==0) {
            B.append(p->data);
        }
        p = p->next;
    }
};

