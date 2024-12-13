#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int f[200]={0};
	f[0] = 1;
	f[1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i]+=f[j]*f[i-1-j];
		}
	}
	cout<<f[n]<<endl;
	return 0; 
}
