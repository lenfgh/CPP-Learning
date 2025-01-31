#include<stdio.h>
#include<string.h>

char base64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
;

char transf(int byte){
    return base64[byte];
}

void output64_0(char* c){
    unsigned char o1 = transf(((*c) >> 2) & 0b00111111);
    unsigned char o2 = transf(((*(c + 1)) >> 4) | (((*c) << 4) & (0b00110000)));
    unsigned char o3 = transf(((0b00111100) & (*(c + 1) << 2)) | (*(c + 2) >> 6));
    unsigned char o4 = transf(((0b00111111) & (*(c + 2))));
    printf("%c%c%c%c",o1,o2,o3,o4); 
}

void output64_1(char* c){
    unsigned char o1 = transf(((*c) >> 2) & 0b00111111);
    unsigned char o2 = transf(((*(c + 1)) >> 4) | (((*c) << 4) & (0b00110000)));
    unsigned char o3 = transf(((0b00111100) & (*(c + 1) << 2)));
    unsigned char o4 = '=';
    printf("%c%c%c%c",o1,o2,o3,o4); 
}

void output64_2(char* c){
    unsigned char o1 = transf(((*c) >> 2) & (0b00111111));
    unsigned char o2 = transf(((*c) << 4) & (0b00110000));
    unsigned char o3 = '=';
    unsigned char o4 = '=';
    printf("%c%c%c%c",o1,o2,o3,o4); 
}

char input[40];

int main(){
    gets(input);
0
    int len = strlen(input);

    int i = 0;

    for(;i+2<=len-1;){
        output64_0(input+i);
        i+=3;
    }
    
    if(len-1 - i ==0){
        output64_2(input+i);
    }

    if(len-1 - i ==1){
        output64_1(input+i);
    }
    printf("\n");
    return 0;

}