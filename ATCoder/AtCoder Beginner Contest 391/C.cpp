//
// Created by FUGUO on 2025/2/2.
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//TLE
//int main() {
//    int N,Q;
//    cin >> N >> Q;
//    vector<vector<int>> nests(N+1);
//    for (int i=1; i<=N; i++) {
//        nests[i].push_back(i);
//    }
//    for (int i=0; i<Q; i++) {
//        int q1,q2,q3;
//        cin >> q1;
//        if (q1==1) {
//            cin >> q2 >> q3;
//            for (auto &nest : nests) {
//                if (nest.empty()) continue;
//                for (auto it = nest.begin(); it != nest.end(); ) {
//                    if (*it == q2) {
//                        it = nest.erase(it);  // 删除元素并返回下一个迭代器
//                    } else {
//                        ++it;
//                    }
//                }
//            }
//            nests[q3].push_back(q2);
//        } else {
//            int count = 0;
//            for (int j=1; j<=N; j++) {
//                if (nests[j].size()>1) {
//                    count++;
//                }
//            }
//            cout << count << endl;
//        }
//    }
//    return 0;
//}

//int main() {
//    int N,Q;
//    cin >> N >> Q;
//    vector<vector<int>> nests(N+1);
//    unordered_map<int,int> penguins;
//
//    for (int i=1; i<=N; i++) {
//        nests[i].push_back(i);
//        penguins[i] = i;
//    }
//
//    for (int i=0; i<Q; i++) {
//        int q1,q2,q3;
//        cin >> q1;
//        if (q1==1) {
//            cin >> q2 >> q3;
//            int nest_q2 = penguins[q2];
//            for (auto it = nests[nest_q2].begin(); it != nests[nest_q2].end();) {
//                if (*it == q2) {
//                    nests[nest_q2].erase(it);
//                } else {
//                    it++;
//                }
//            }
//            penguins[q2] = q3;
//            nests[q3].push_back(q2);
//        } else {
//            int count = 0;
//            for (auto it: nests) {
//                if (it.size()>1) {
//                    count++;
//                }
//            }
//            cout << count << endl;
//        }
//    }
//    return 0;
//}

int main() {
    int N,Q;
    cin >> N >> Q;
    unordered_map<int,int> nests(N+1);
    unordered_map<int,int> penguins(N+1);

    for (int i=1; i<=N; i++) {
        nests[i] = 1;
        penguins[i] = i;
    }
    int count = 0;
    for (int i=0; i<Q; i++) {
        int q1,q2,q3;
        cin >> q1;
        if (q1==1) {
            cin >> q2 >> q3;
            int nest_q2 = penguins[q2];
            penguins[q2] = q3;
            int num_ori = nests[nest_q2];
            nests[nest_q2]--;
            if (nests[nest_q2] <= 1 && num_ori>1) {
                count--;
            }
            int num_ori_q3 = nests[q3];
            nests[q3]++;
            if (nests[q3] > 1 && num_ori_q3 <=1) {
                count ++;
            }
        } else {
            cout << count << endl;
        }
    }
    return 0;
}
