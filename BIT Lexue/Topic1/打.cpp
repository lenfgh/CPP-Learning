#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,j,i,t;
	scanf("%d %d",&n,&m);
	if(n%2==0){
		for(i=1;i<=n;i++){
			
			for(j=0;j<=6*n-2*i-4;j++){
				if(i==1||i==n){
				if(j<2*(i-1)){
					cout<<' ';
				}
				else{
				if(abs(j-3*n+3)%2==0){
				cout<<' ';
				}
				else{
				    printf("%d",(m+3*n/2-2-abs(j-3*n+3)/2)%10);
			    }
			    }
			    }
			    else{
			    	if(j==2*i-2||j==6*n-2*i-4){
			    		cout<<(m+3*n/2-2-abs(j-3*n+3)/2)%10;
					}
					else{
						cout<<' ';
					}
				}
			    
			}
			cout<<'\n';
	    }		
	}
	if(n%2==1){
	    for(i=1;i<=n;i++){
			for(j=0;j<=6*n-2*i-4;j++){				

				if(i==1||i==n){				
				    if(j<2*(i-1)){
					cout<<' ';
				}
				else{
				if(abs(j-3*n+2)%2==0){
				cout<<' ';
				}
				else{
				    printf("%d",(m+3*n/2-3/2-abs(j-3*n+3)/2)%10);
			    }
			    }
			    }
			    else{
			    	
			    	if(j==2*(i-1)||j==6*n-2*i-4){
			    		cout<<(m+3*n/2-3/2-abs(j-3*n+3)/2)%10;
					}
					else{
						cout<<' ';
					}
				}
			    
			}
			cout<<'\n';
	    }
		
	}
	return 0;
}
