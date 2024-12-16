#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	double X,sum=0;
	cin>>x;
	X=x/30*0.5235987667;
	double dn(float y,int i);
	int i=0;
	for (;;i++){
		sum+=dn(X,i);
		if(fabs(dn(X,i))<1e-6){
			break;
		}
	}
	cout<<i<<',';
	cout<<"cos("<<x<<')'<<'=';
	cout<<"cos("<<fixed<<setprecision(6)<<X<<")=";
	cout<<fixed<<setprecision(6)<<sum<<endl;
	return 0;
}

long long floor(int n){
	int i;
	long long m=1;
	for(i=1;i<=n;i++){
		m*=i;
	}
	return m;
}
double e2p(float x,int n){
	int i;
	double m;
	for(i=1,m=1;i<=n;i++){
		m*=x;
	}
	return m;
}
double dn(double y,int i){
	double e2p(float x,int n);
	double m;
	m=e2p(-1,i)*e2p(y,2*i)/floor(2*i);
	return m;
} 
