#include<iostream>

# define ll long long

using namespace std;

ll input[100001][3];

ll dp[30][30][30];

ll w(ll a,ll b,ll c){
	if((a<=0)||(b<=0)||(c<=0)){
		dp[a][b][c] =1;
		return 1;
	}
	else if((a>20)||(b>20)||(c>20)){
		return w(20,20,20);
	}
    else if((a<b)&&(b<c)){
    	if(dp[a][b][c-1]==0)dp[a][b][c-1] = w(a,b,c-1);
    	if(dp[a][b-1][c-1]==0)dp[a][b-1][c-1] = w(a,b-1,c-1);
    	if(dp[a][b-1][c]==0)dp[a][b-1][c] = w(a,b-1,c);
    	dp[a][b][c] =dp[a][b][c-1]+dp[a][b-1][c-1]-dp[a][b-1][c];
    	return dp[a][b][c];
	}
	else{
		if(dp[a-1][b][c]==0) dp[a-1][b][c] = w(a-1,b,c);
		if(dp[a-1][b-1][c]==0) dp[a-1][b-1][c] = w(a-1,b-1,c);
		if(dp[a-1][b][c-1]==0) dp[a-1][b][c-1] = w(a-1,b,c-1);
		if(dp[a-1][b-1][c-1]==0) dp[a-1][b-1][c-1] = w(a-1,b-1,c-1);
		dp[a][b][c] =dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
		return dp[a][b][c];
	}
}
 int main(){
	ll w(ll a,ll b,ll c);
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
