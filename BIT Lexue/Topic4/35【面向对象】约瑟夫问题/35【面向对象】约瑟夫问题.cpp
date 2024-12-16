// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=469052
// Created by Len Fu on 2024/12/16.
//

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

class Joseph
{
private:
    struct node {
        int data;
        node * next;

        node(int d, node *p=NULL) : data(d), next(p) {  }
    };
    node * head;
public:
    Joseph(int n);  //构造函数
    void outJoseph();           //输出环
    void simulate(int m, int k);    //对约瑟夫环中的结点进行计数，以m为步长将结点依次出环
    ~Joseph();              //析构函数
};

Joseph::Joseph(int n)       //构造函数
{
    node *tail;
    //建立有表头结点的环型链表
    head = tail = new node(-1); //创建第一个结点，head指向表头，p指向表尾
    for ( int i=0; i<n; ++i ) {
        tail->next = new node(i);
        tail = tail->next;
    }
    tail->next = head;               //头尾相连
}

Joseph::~Joseph()
{
    node *p;
    if (head==NULL) return;
    while (head->next!=head) {
        p = head->next;
        head->next = p->next;
        delete p;
    }
    delete head;
}

void Joseph::outJoseph()
{
    node *p;
    p = head;
    while ( p->next!=head ) {
        p = p->next;
        cout << p->data << ",";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int n, m, k;    //n个
    cin >> n >> m >> k;
    Joseph h(n);
//  h.outJoseph();
    h.simulate(m, k);
    h.outJoseph();
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void Joseph::simulate(int m, int k) {

    int count = 1;
    node * p;

    p = head -> next;

    node * temp = p;

    for (; count <= k; count++) {
        if(count != 1){
            cout << ",";
        }

        if(m==1) {
            temp = p;
        } else {
            for(int i=1; i<=m-1; i++) {
                p = p->next;
                if(p==head) {
                    i--;
                }
            }
            temp = p;
        }

        for(;p->next != temp ;) {
            p = p->next;
        }

        p -> next = temp -> next;

        p = temp -> next;

        if(p == head) {
            p = p -> next;
        }

        cout << temp->data ;
//        cout << '"' << p->data << '"' ;
    }

    cout << endl;

};

