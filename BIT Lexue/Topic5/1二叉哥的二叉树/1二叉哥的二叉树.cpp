// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476062
// created.by.Len Fu 12.23.2024
//
#include <math.h>
#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int num=0;

void count(int n,int m){
    if(n<m+1){		//只放一个都不够
        num+=0;
        return;
    }
    else if(n==m+1){	//只放一个刚刚好
        num+=1;
        return ;
    }
    else{
        n=n-m-1;	//每层放一个之后剩下的
        num += 1;	///每层放一个那么m层就有1个了哦
        int layer=1;	//第0层已经有了，直接开始第1层吧

        if(n==0||layer>m)		//没有节点了，或者层数已经够了，结束递归
            return;
        int need;
        need=pow(2,layer)-1;		//放满需要的节点数

        while(n-need>0){	//只要能放满还剩，重复一直放
            num+=pow(2,layer-1);
            layer++;
            n-=need;
            need=pow(2,layer)-1;
            if(layer>m)		//注意判断是否达到了退出的条件
                return ;
        }
        if(n-need==0){	//刚好放满
            num+=pow(2,layer-1);
            return;
        }
        else			//新的一层不够放，那么当做一个新的情况开始递归吧
            count(n,layer-1);

    }

}
int main() {
    int n,m,t;
    //freopen("file in.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>m;
        num=0;		//每一次都要初始化，不然会累加
        count(n,m);
        cout<<num<<endl;
    }

    return 0;
}
