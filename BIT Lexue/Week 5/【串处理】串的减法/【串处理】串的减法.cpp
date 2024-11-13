// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=468944
// created by FUGUO 24.11.12
//
#include<iostream>
#include<string>
#include<queue>
using namespace std;

queue <char> temp;

string input1,input2;

int main(){
    
    cin >> input1 >> input2;

    for(int i=0;input1[i]!='\0';i++){
        char check = input1[i];
        bool yn=true;
        for(int j = 0;input2[j]!='\0';j++){
            if(check == input2[j]){
                yn = false;
                break;
            }
        }
        if(yn){
            temp.push(check);
        }
    }

    for(;!temp.empty();){
        cout << temp.front();
        temp.pop();
    }
    cout << endl;
    return 0;


}

