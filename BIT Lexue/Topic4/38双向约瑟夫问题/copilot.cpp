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
};

Joseph::Joseph(int n) {
    node * p, * q;
    head = new node(1);
    p = head;
    for (int i = 2; i <= n; ++i) {
        q = new node(i);
        p->next = q;
        q->last = p;
        p = q;
    }
    p->next = head;
    head->last = p;
}

Joseph::~Joseph() {
    node * p = head, * q;
    do {
        q = p->next;
        delete p;
        p = q;
    } while (p != head);
}

void Joseph::simulate(int n, int m, int k) {
    node * p = head;
    while (p->index != k) {
        p = p->next;
    }

    while (n > 0) {
        for (int i = 1; i < m; ++i) {
            p = p->next;
        }
        node * q = p;
        for (int i = 1; i < m; ++i) {
            q = q->last;
        }

        if (p == q) {
            cout << p->index;
            p->last->next = p->next;
            p->next->last = p->last;
            node * temp = p->next;
            delete p;
            p = temp;
            --n;
        } else {
            cout << p->index << "-" << q->index;
            p->last->next = p->next;
            p->next->last = p->last;
            q->last->next = q->next;
            q->next->last = q->last;
            node * temp = p->next;
            delete p;
            p = temp;
            delete q;
            n -= 2;
        }

        if (n > 0) {
            cout << ",";
        }
    }
    cout << endl;
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m) {
        Joseph joseph(n);
        joseph.simulate(n, m, k);
    }
    return 0;
}