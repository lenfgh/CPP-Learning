// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=468944
// created by FUGUO 24.11.14
//
#include<stdio.h>

char input1[90],input2[90];

char temp[90];

int main(){
    gets(input1); // For this problem, using scanf isn't correct, since it may occur " " and it will end but gets() will not.
    gets(input2);

    int i=0;
    for(int j=0;input1[j]!='\0';j++){
            char check = input1[j];
            int  yn =1;
            for(int k=0;input2[k]!='\0';k++){
                if(check==input2[k]){
                    yn=0;
                    break;
                }

            }
            if(yn){
                temp[i]=check;
                i++;
            }            
    }
    temp[i] = '\0';
    for(int l=0;temp[l]!='\0';l++){
        printf("%c",temp[l]);
    }
    printf("\n");
    return 0;
}