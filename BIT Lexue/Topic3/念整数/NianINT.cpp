// This is the solution of the
// Created by FUGUO on 2024/11/6.
//
#include<stdio.h>

void speak(char x){
    switch(x){
        case '-': printf("fu");break;
        case '1': printf("yi");break;
        case '2': printf("er");break;
        case '3': printf("san");break;
        case '4': printf("si");break;
        case '5': printf("wu");break;
        case '6': printf("liu");break;
        case '7': printf("qi");break;
        case '8': printf("ba");break;
        case '9': printf("jiu");break;
        case '0': printf("ling");break;
        default: break;
    }
}

char input[10];

int main(){
    scanf("%s",input);
    speak(input[0]);

    int i=1;
    while(input[i]!='\0'){

        printf(" ");
        speak(input[i]);
        i++;
    }
    printf("\n");
    return 0;

}