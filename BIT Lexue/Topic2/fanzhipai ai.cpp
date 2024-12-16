#include<bits/stdc++.h>
using namespace std;
int x;
int dp[20][2][2];
char b_str[20];

int dfs(int pos,int limit, int leading_zero){
	if(pos == strlen(b_str)){
		return 1;
	}
	if(dp[pos][limit][leading_zero] != -1){
		return dp[pos][limit][leading_zero];
	}
	int max_digit = limit?(b_str[pos]-'0'):x;
	int result = 0;
	for(int digit = 0;digit<=max_digit;digit++){
		if(digit == 0&&leading_zero){
			result +=dfs(pos+1,limit&&(digit == max_digit),1);
		}
		else if(digit <= x){
			result += dfs(pos+1,limit&&(digit == max_digit),0);
		}
	}
	return dp[pos][limit][leading_zero] = result;
}


int solve(int num){
	sprintf(b_str,"%d",num);
	memset(dp,-1,sizeof(dp));
	return dfs(0,1,1);
}

int main(){
	int a,b;
	scanf("%d %d %d",&x,&a,&b);
	int result_b = solve(b);
	int result_a = solve(a-1);
	printf("%d\n",result_b-result_a);
}
