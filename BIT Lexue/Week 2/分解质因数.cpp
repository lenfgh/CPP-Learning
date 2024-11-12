#include<stdio.h>
/*int main(){
	int m,j;
    scanf("%d",&m);
    unsigned long long a[10];
    for(j=0;j<m;j++){
    	scanf("%lld",&a[j]);
	}
	for(j=0;j<m;j++){
    unsigned long long  i;
    printf("%lld = ",a[j]);
    for(i=2;i<=a[j];i++)
    {
        while(a[j]%i==0)
        {
            printf("%lld",i);
            a[j]/=i;
            if(a[j]!=1) printf(" * ");
        }
    }
    
    printf("\n");
	}
	return 0;
}*/
#include <stdio.h>
#include <math.h>

int main() {
    int m;
    scanf("%d", &m);
    unsigned long long a[10];
    for (int j = 0; j < m; j++) {
        scanf("%lld", &a[j]);
    }
    for (int j = 0; j < m; j++) {
        unsigned long long num = a[j];
        printf("%lld = ", num);
        // 处理2的因子
        if (num % 2 == 0) {
            
            while (num % 2 == 0) {
                num /= 2;
				printf("2");
                if (num != 1) printf(" * ");
            }
        }
        // 处理奇数因子
        for (unsigned long long i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                printf("%lld", i);
                while (num % i == 0) {
                    num /= i;
                    if (num != 1) printf(" * ");
                }
            }
        }
        // 如果剩余的数大于2，则它本身是质数
        if (num > 2) {
            printf("%lld", num);
        }
        printf("\n");
    }
    return 0;
}
