#include<bits/stdc++.h>
using namespace std;
int main(){
	bool compare(double x,double y);
	int i,n,m;
	cin>>n>>m;
	int a[2][10001]={0};
	int b[10001]={0};
	double y[10001]={0};
	double d; 
	cin>>a[0][0];	
	for(i=1;i<=n-1;i++){
		cin>>a[0][i]>>a[1][i];
	}
	b[1]=a[0][0]+a[0][1]-a[1][1];
	if(b[1]>=m){
		b[1]=m;
	}
	if(b[1]<=0){
		b[1]=0;
	}
	y[1]=(double)b[1]/m;
	cout<<fixed<<setprecision(3)<<y[1]<<endl;
	d=y[1];
	for(i=2;i<=n-1;i++){
		b[i]=b[i-1]+a[0][i]-a[1][i];
		if(b[i]>=m){
			b[i]=m;
		}
		if(b[i]<=0){
			b[i]=0;
		}
		y[i]=(double)b[i]/m;
		d=y[i]<d?y[i]:d;
		cout<<fixed<<setprecision(3)<<y[i]<<endl;
	}
	
	for(i=1;i<=n-1;i++){
		if(d==y[i]){
			cout<<i<<',';
		}
	}
	cout<<endl;
	return 0;
}

