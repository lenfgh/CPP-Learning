#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[3];
	for(int i=0;i<3;i++){
		scanf("%d",&a[i]);
	}
	int n;
	scanf("%d",&n);
    a[2]+=n;
	for(;;)	
		if(a[1]==1||a[1]==3||a[1]==5||a[1]==7||a[1]==8||a[1]==10||a[1]==12){
			if(a[2]<32){
				break;
			}
			a[1]+=1;
			a[2]-=31;
			
		}
		else if(a[1]==2){
				if((a[0]%4==0&&a[0]%100!=0)||a[0]%400==0){
					if(a[2]<=29){
						break;
					}
					a[1]+=1;
				    a[2]-=29;
			    }
			    else{
			    	if(a[2]<=28){
                           break;
					}
					a[1]+=1;
			    	a[2]-=28;
				}
			}
		else {
			if(a[2]<31){
				break;
			}
			a[1]+=1;
			a[2]-=32;
		}
		if(a[1]>12){
			a[0]+=1;
			a[1]-=12;
		}
	
	printf("%d.%d.%d",a[0],a[1],a[2]);
	return 0;
}
