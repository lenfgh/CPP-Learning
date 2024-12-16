#include<bits/stdc++.h>
using namespace std;
int main(){
	int po(int x);
	int n,i,j,k=1;
	cin>>n;
	int s=pow(2,2+n);
	int a[s][s];
    //初始化 
	for(i=0;i<s;++i){  
        for(j=0;j<s;++j){  
            a[i][j]=' ';  
        }  
    }  
	//迭代囧心 
	for(k=1;k<=n;k++){
		for(j=s/2-1,i=s+1-(4*po(k)-2);j>=(s/2-po(1+k)+3),i<=1+s-(4*po(k-1)+2);j--,i++){
			a[i-1][j-1]='/';
		}
		for(j=s/2+2,i=s+1-(4*po(k)-2);j<=(s/2+po(1+k)-2),i<=1+s-(4*po(k-1)+2);j++,i++){
			a[i-1][j-1]='\\';
		}
	} 	
	//迭代| 
	for(k=0;k<=n;k++){
		for(i=s;i>=s+1-po(2+k);i--){
			a[i-1][s/2+po(k+1)-1]='|';
			a[i-1][s/2-po(1+k)]='|';
		}
	}
	//上下顶
	for(j=0;j<s;j++){
		a[0][j]='-';
		a[s-1][j]='-';
	} 
	//迭代-
	for(k=0;k<=n;k++){
		for(j=s/2-po(1+k);j<=s/2+po(k+1)-1;j++){
			a[s-po(k+2)][j]='-';
		}
	} 
    //迭代四角 
	for(k=0;k<=n;k++){
		a[s-po(2+k)][s/2-po(1+k)]='+';
		a[s-po(2+k)][s/2+po(k+1)-1]='+';
		a[s-1][s/2-po(1+k)]='+';
		a[s-1][s/2+po(k+1)-1]='+';
	}
	// 输出 
	for(i=1;i<=s;i++){
		for(j=1;j<=s;j++){
			printf("%c",a[i-1][j-1]);
		}
		cout<<endl;
	}
	return 0;
}
int po(int x){
	int n=1;
	for(int i=0;i<x;i++){
		n*=2;
	}
	return n;
}
	

