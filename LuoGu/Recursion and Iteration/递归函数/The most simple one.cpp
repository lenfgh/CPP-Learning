#include<iostream>
#include<cstdio>

using namespace std;

int w(int a,int b, int c){
	if((a<=0)||(b<=0)||(c<=0)){
		return 1;
	}
	else if((a>20)||(b>20)||(c>20)){
		return w(20,20,20);
	}
    else if((a<b)&&(b<c)){
    	return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	else{
		return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
}

int main(){
	int w(int a,int b, int c);
	int a[20][3];
	int i;
	for(i=0;i<20;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		if((a[i][0]==-1)&&(a[i][1]==-1)&&(a[i][2]==-1)){
			break;
		}
	}
	for(int j=0;j<i;j++){
		cout<<w(a[j][0],a[j][1],a[j][2])<<endl;
	}
	return 0;
}


