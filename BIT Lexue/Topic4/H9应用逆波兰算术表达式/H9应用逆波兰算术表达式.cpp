// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=469019
// Created by FUGUO on 2024/12/17.
//
#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

stack <int> temp;

int main() {
    int output=0;
    string input;

    getline(cin, input);

    stringstream ss(input);
    string token;

    while(getline(ss,token,' ')) {

//        cout << "check 0" << endl;

//        cout << 'i' <<token << endl;

        size_t pos1 = token.find('/');
        size_t pos2 = token.find('*');
        size_t pos3 = token.find('+');
        size_t pos4 = token.find('-');
        size_t size = token.size();

        if ( size==1) {
            if (pos1 != string::npos) {
                int num1 = temp.top();
                temp.pop();
                int num2 = temp.top();
                temp.pop();
                int num3 = num2 / num1;
                temp.push(num3);
                output = num3;
            } else if (pos2 != string::npos) {
                int num1 = temp.top();
                temp.pop();
                int num2 = temp.top();
                temp.pop();
                int num3 = num1 * num2;
                temp.push(num3);
                output = num3;
                //            cout << num1 << ' ' << num2 << ' ' << num3 << endl;
            } else if (pos3 != string::npos) {
                int num1 = temp.top();
                temp.pop();
                int num2 = temp.top();
                temp.pop();
                int num3 = num1 + num2;
                temp.push(num3);
                output = num3;
                //            cout << num1 << ' ' << num2 << ' ' << num3 << endl;
            } else if (pos4 != string::npos) {
                int num1 = temp.top();
                temp.pop();
                int num2 = temp.top();
                temp.pop();
                int num3 = -num1 + num2;
                temp.push(num3);
                output = num3;
                //            cout << num1 << ' ' << num2 << ' ' << num3 << endl;
            } else {
                int num0 = stoi(token);
                temp.push(num0);
//                cout << "continue" << num0 << endl;
            }
        } else {
            int num0 = stoi(token);
            temp.push(num0);
//            cout << "continue" << num0 << endl;
        }
    }

    cout << output << endl;
    return 0;
}
