#include<iostream>

using namespace std;



int main(){
	int dp[20][20] = {0};
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		dp[i][0]=1;	
	}
	
	for(int j=1;j<=n;j++){
		for(int i=0;i<n;i++){
			if(0==i){
				dp[i][j]=dp[i+1][j-1];
				continue;
			}
			dp[i][j] = dp[i-1][j]+dp[i+1][j-1]; 
		}
	}
	cout<<dp[0][n]<<endl;
	return 0;
	
} 
