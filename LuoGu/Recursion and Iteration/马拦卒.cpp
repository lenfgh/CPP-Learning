#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long

using namespace std;

const int Horse_move_x[8]={2,2,1,1,-1,-1,-2,-2};
const int Horse_move_y[8]={1,-1,2,-2,2,-2,1,-1};



int main(){
	int Bx;
	int By;
	int Horse_x;
	int Horse_y;

	ll f[22][22];
	int s[22][22];
	for(int i = 0;i<22;i++){
		for(int j =0;j<22;j++){
			s[i][j]=1;
			f[i][j]=0;
		}
	}
	scanf("%d%d%d%d",&Bx,&By,&Horse_x,&Horse_y);
	s[Horse_x+1][Horse_y+1] = 0;
	for(int i = 0;i<8;i++){
		int x = 1+Horse_x+Horse_move_x[i];
		int y = 1+Horse_y+Horse_move_y[i];
		if((x<=0)||(y<=0)||(x>Bx)||(y>By)){
			continue;
		}
		s[x][y] = 0;
	}
	f[1][1] = 1;
	
	for(int i=1;i<=Bx;i++){
		for(int j=1;j<=By;j++){
			f[i+1][j+1] = (f[i][j+1]+f[i+1][j])*s[i+1][j+1];
			cout<<i+1<<" "<<j+1<<" "<<f[i+1][j+1]<<" "<<s[i+1][j+1]<<endl;
		}
	}
	cout<<f[Bx+1][By+1]<<endl;
	return 0;
}

