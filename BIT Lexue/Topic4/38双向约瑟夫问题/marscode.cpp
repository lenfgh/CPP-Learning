#include <iostream>
#include <cstdio>
using namespace std;

class Joseph {
private:
    struct node {
        int index;
        node *next;
        node *last;
        node(int x, node *p = NULL, node *q = NULL) : index(x), next(p), last(q) {}
    };
    node *head;

public:
    Joseph(int n);
    ~Joseph();
    void simulate(int n, int m, int k);
    void printList(); // Add a function to print the list for debugging
};

Joseph::Joseph(int n) {
    node *p;
    node *temp;
    head = p = new node(1); // Initialize head with 1 instead of 0
    for (int i = 2; i <= n; i++) {
        temp = p;
        p->next = new node(i);
        p = p->next;
        p->last = temp;
    }
    p->next = head;
    head->last = p;
}

Joseph::~Joseph() {
    node *p = head;
    if (head == NULL) {
        return;
    } else {
        do {
            node *temp = p;
            p = p->next;
            delete temp;
        } while (p != head);
    }
}

void Joseph::printList() {
    node *p = head;
    do {
        cout << p->index << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void Joseph::simulate(int n, int k, int m) {
    if (k > n) {
        cout << "k should not be bigger than n." << endl;
        return;
    }
    if (k * n * m == 0) {
        cout << "n, m, k must be bigger than 0." << endl;
        return;
    }

    node *p1 = head;
    node *p2 = head;

    // Move p1 and p2 to the starting position k
    for (int i = 1; i <=k; i++) {
        p1 = p1->next;
        p2 = p2->next;
    }

    while (n > 0) {
        // Print the current list for debugging
        // cout << "Current list: ";
        // printList();

        if (n == 1) {
            cout << p1->index << ',';
            break;
        }

        // Move p1 clockwise m steps
        for (int i = 1; i < m; i++) {
            p1 = p1->next;
            if (p1 == head) i--;
        }

        // Move p2 counterclockwise m steps
        for (int i = 1; i < m; i++) {
            p2 = p2->last;
            if (p2 == head) i--;
        }

        if (p1 == p2) {
            cout << p1->index << ',';
            p1->last->next = p1->next;
            p1->next->last = p1->last;
            // node *temp1 = p1->next;
            // node *temp2 = p1->last;
            // delete p1;
            // delete p2;
            p1 = p1->next;
            p2 = p1->last;
            n--;
        } else {
            cout << p1->index << '-' << p2->index << ',';
            p1->last->next = p1->next;
            p1->next->last = p1->last;
            p2->last->next = p2->next;
            p2->next->last = p2->last;
            node *temp1 = p1->last->next;
            node *temp2 = p2->next->last;
            delete p1;
            delete p2;
            p1 = temp1;
            p2 = temp2;
            n -= 2;
        }

        if(p1 == head) p1 = p1->next;
        if(p2 == head) p2 = p2->last;

    }
    cout << endl;
}

int main() {
    int n, m, k;
    scanf("%d,%d,%d", &n, &m, &k);
    Joseph h(n);
    h.simulate(n, m, k);

    return 0;
}