#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0,basb=0,basa=0,temp,sum=0,l,s;
	string a,b;
	int rams[11]={0},raml[11]={0},plus[11]={0},minus[11]={0};
	cin>>n>>a>>b;
	for(int i=0;i<a.size();i++){
		rams[i]=a[a.size()-i-1]-'0';
	}
	for(int i=0;i<b.size();i++){
		raml[i]=b[b.size()-i-1]-'0';
	}
    cout<<a.size()<<' '<<b.size()<<endl;	//¼ÆËã×î¶à
	for(int i = 0; i<b.size();i++){
		
		int bb = raml[i]>n?n+1:raml[i];
		plus[i] = (int)bb*pow(n+1,i);
		/*
		if(i==0){
			plus[i]-=1;
		}
		if(raml[i]==0){
			plus[i] = 0;
		}
		*/
		
	}
	for(int i = 0; i<a.size();i++){
		int aa = rams[i]>n?n+1:rams[i];	
		minus[i] = (int)aa*pow(n+1,i);
		//if(rams[i]==0){
		//	minus[i] = 0;
		//}
	}
	for(int i = 0;i<b.size();i++){
		printf("%d ",raml[i]);
	}
	printf("\n");
	for(int i = 0;i<b.size();i++){
		printf("%d ",plus[i]);
	}
	for(int i = 0; i<b.size();i++){
		sum+=(plus[i]-minus[i]);
	}
    
    if(rams[a.size()-1]>n){
    	sum = 0;
	}
    cout<<sum<<endl;
	return 0;
}
