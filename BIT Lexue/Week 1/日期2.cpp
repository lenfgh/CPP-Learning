#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[3],b[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	int dim[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int sum=0,del=0;
	for(;a[0]<b[0];){
		if((a[0]%4==0&&a[0]%100!=0)||a[0]%400==0){
			a[0]+=1;
			sum+=366;
		}
		else{
			a[0]+=1;
			sum+=365;
		}
	}
	del=(a[0]%4==0&&a[0]%100!=0)||a[0]%400==0;
	for(;a[1]!=b[1];){
		if(del){
			dim[1]=29;
		}
		if(a[1]>b[1]){
			sum-=dim[a[1]-1];
			a[1]-=1;
		}
		else{
			sum+=dim[a[1]-1];
			a[1]+=1;
		}
	}
	sum+=(b[2]-a[2]);
	if(sum==1){
		printf("1 day\n");
	}
	else{
		printf("%d days\n",sum);
	}
	return 0;
}
