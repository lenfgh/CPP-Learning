#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,i,a,temp,del;
	scanf("%d/%d",&n,&m);
	temp = n*10;
		cout<<"0.";
	for(i=0;i<200;i++){
		a=temp/m;
		del = temp%m;
		cout<<a;
		if(del == 0){
			break;
		}
		temp = del*10;

	}
	cout<<endl;
	return 0;
}
