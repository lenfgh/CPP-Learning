// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476056&forceview=1
// Created by FUGUO on 2024/12/23.
//
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Group {
private:
    int num_state;
    int time=0;
    int tot_goods;
    struct car {
        int max;
        stack<int> goods;
        car(int n): max(n), goods() {};
    };
    car mycar;
    struct state {
        int index;
        int max;
        queue<int> B;
        state * next;
        state(int x, int a, state * p=NULL): index(x), max(a) , B(), next(p){};
    };
    state * head;
public:
    Group(int N, int S, int Q);
    ~Group();
    void transport();
};

Group::Group(int N, int S, int Q): mycar(S) {
//    cout << "car's max=" << mycar.max << endl;
    state * p;
    num_state = N;
    tot_goods = 0;
    head = new state(0,Q);
    p = head;
    for( int i=1; i<=N; i++) {
        p->next = new state(i,Q);
//        cout << p->next->index << "is inputting" << endl;
        int tot;
        cin >> tot;
        tot_goods += tot;
//        cout << "Goods are "<< tot_goods << endl;
        if (tot != 0) {
            for (int j = 1; j <= tot; j++) {
                int to;
                cin >> to;
                p->next->B.push(to);
            }
        }
//        cout << "End inputting" << endl;
        p = p->next;
    }
    p -> next = head;
};

Group::~Group() {
    state * p;
    if (head==NULL) return;
    while (head->next!=head) {
        p = head->next;
        head->next = p->next;
        delete p;
    }
    delete head;
};

void Group::transport() {
//    cout << "Goods are " << tot_goods << endl;
    state * current;
    current = head;
    while(tot_goods>0) {
        if(current == head) {
            current = current->next;
        }
//        cout << "Now is in" << current->index << "Goods are left with" << tot_goods <<endl;
        while(true) {
//            cout << current->B.size() << "in it with max=" << current->max << endl;

            if(!mycar.goods.empty()) {
//                cout << mycar.goods.top() <<  "good" << endl;
                while(true) {
                    if (mycar.goods.empty()) break;
                    if (mycar.goods.top() == current->index) {
                        mycar.goods.pop();
                        time += 1;
                        tot_goods -= 1;
                        if(tot_goods==0) goto END;
//                        cout << "->A" << endl;
                    } else {
                        break;
                    }
                }
            } else if(current->B.empty()) {
                current = current -> next;
                time +=2 ;
//                cout << "Skip Stop" << endl;
                break;
            }

            if (mycar.goods.empty() || current->B.size()==current->max) {
                while(true) {
                    if (current->B.empty()||mycar.goods.size()==mycar.max) {
//                        cout << "Stop In" << endl;
                        break;
                    }
                    mycar.goods.push(current->B.front());
                    current->B.pop();
                    time += 1;
//                    cout << "In" << endl;
                }//装一次货
                current = current -> next;
//                cout << "Next stop" << endl;
                time += 2;
                break;
            }

            if(current->index!=mycar.goods.top()) {

                current->B.push(mycar.goods.top());
                mycar.goods.pop();
                time += 1;
//                cout << "->B" << endl;

            }//卸货

        }
    }//全过程
    END:
    cout << time << endl;
}

int main() {
    int SET;
    cin >> SET;
    for(int i=0; i<SET;i++) {
        int n,s,q;
        cin >> n >> s >> q;
        Group h(n,s,q);
//        cout << "Begin calculating" << endl;
        h.transport();
    }
    return 0;
}




