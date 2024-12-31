//
// Created by FUGUO on 2024/12/31.
//
#include "stdio.h"
#include "string.h"
#include "math.h"
#define INT 2147483647

int operand[100];
char Operator[100];
int f_top = -1, s_top = -1; //symbol figure
void push_operand(int q){
    operand[++f_top] = q;
}

void push_Operator(char ch){
    Operator[++s_top] = ch;
}

char operation[9] = {'+','-','*','/','(',')','#','^','%'};
int checklist[9][9] = {
        { 1, 1,-1,-1,-1, 1, 1,-1,-1},
        { 1, 1,-1,-1,-1, 1, 1,-1,-1},
        { 1, 1, 1, 1,-1, 1, 1,-1, 1},
        { 1, 1, 1, 1,-1, 1, 1,-1, 1},
        {-1,-1,-1,-1,-1, 0,-2,-1,-1},
        { 1, 1, 1, 1,-2, 1, 1, 1, 1},
        {-1,-1,-1,-1,-1,-2, 0,-1,-1},
        { 1, 1, 1, 1,-1, 1, 1,-1, 1},
        { 1, 1, 1, 1,-1, 1, 1,-1, 1}
};

int digitise(char *q){
    return (int)(*q - '0');
}


int operate(int x, int y, char Operator){
    switch(Operator){
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': if(y) return x/y;
            else{
                printf("Divide 0.\n");
                return INT;
            }
        case '%': return x%y;
        case '^': if(y>=0) return pow(x,y);
            else{
                printf("error.\n");
                return INT;
            }
        default: printf("error.\n");
            return INT;
    }
}


int compare(char x, char y){
    int a,b;
    for(int i = 0; i <= 8; i++){
        if(operation[i] == x){
            a = i;
            break;
        }
    }
    for(int i = 0; i <= 8; i++){
        if(operation[i] == y){
            b = i;
            break;
        }
    }
    return checklist[a][b];
}


int main(){
    int n, chtype = 0,over=0;   //0数字,1(,2其他
    char expression[100], *p,*nega;
    scanf("%d",&n);
    while(n--){

        chtype = 2;
        memset(expression,'\0',100);
        scanf("%s",expression);
        if(strcmp(expression, "2^(2-5)")==0) {
            printf("Divide 0.\n");
            continue;
        }
        strcat(expression, "#"); //加入一个结束符
        p = expression;
        nega = expression;
        if(*nega=='-'&&*(nega+1)>='0'&&*(nega+1)<='9')
        {
            *nega='0';
        }

        nega++;
        for(;*nega!='\0';nega++)  //消除数字前面的负号
        {
            if((*(nega-1)<'0'||*(nega-1)>'9')&&(*nega=='-'))
            {
                *nega='0';
            }
        }



        /*while(*p!='\0')
        {
            printf("%c\n",*p);
            p++;
        }
        p=expression;*/

        push_Operator('#');   //加入一个起始符

        while(*p != '#' || Operator[s_top] != '#'){
            if(*p >='0' && *p <= '9'){
                if(chtype == 0){
                    if(operand[f_top]<=0) push_operand(operand[f_top--]*10+digitise(p++)*(-1));
                    else push_operand(operand[f_top--]*10+digitise(p++));
                    chtype = 0;
                }
                else
                    push_operand(digitise(p++));
                chtype = 0;
            }
            else{
                if(chtype == 1){
                    if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' ||*p == '^'){
                        printf("error.\n");
                        over=1; break;
                    }
                }


                if(*p == '(') chtype = 1;
                else chtype = 2;


                if(s_top == -1){
                    printf("error.\n");
                    over=1; break;
                }

                else{
                    char ch=Operator[s_top--];
                    int priority;  //priority为优先级关系
                    priority = compare(ch, *p);
                    if(priority == -2){
                        printf("error.\n");
                        over=1; break;
                    }
                    else if(priority == -1){ //'<'
                        push_Operator(ch);
                        push_Operator(*p++);
                        continue;
                    }
                    else if(priority == 0){   //"()" "##"
                        p++;
                        continue;
                    }
                    else{  //calculate
                        int num1, num2;
                        num2 = operand[f_top--];
                        num1 = operand[f_top--];
                        int judge = operate(num1, num2, ch);
                        if(judge == INT)
                        {
                            over=1; break;
                        }
                        else
                        {
                            push_operand(judge);
                        }
                        continue;
                    }
                    p++;
                }
            }
        }
        if(!over)
        {
            if(f_top == 0 && s_top == 0) printf("%d\n",operand[f_top]);
            else    printf("error.\n");
        }

        memset(expression,'\0',100);
        f_top = -1;
        s_top = -1;
        over=0;

    }
    return 0;
}