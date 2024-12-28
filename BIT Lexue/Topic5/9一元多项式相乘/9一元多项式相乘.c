// This is the solution of https://lexue.bit.edu.cn/mod/programming/view.php?id=476048
// Created by FUGUO on 2024/12/24.
// this solution maybe TLE
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag, sign, sum, x;
    char c;

    NODE * p = head;

    while ( (c=getchar()) !='\n' )
    {
        if ( c == '<' )
        {    sum = 0;
            sign = 1;
            flag = 1;
        }
        else if ( c =='-' )
            sign = -1;
        else if( c >='0'&& c <='9' )
        {
            sum = sum*10 + c - '0';
        }
        else if ( c == ',' )
        {    if ( flag == 1 )
            {
                x = sign * sum;
                sum = 0;
                flag = 2;
                sign = 1;
            }
        }
        else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
            p->next->coef = x;
            p->next->exp  = sign * sum;
            p = p->next;
            p->next = NULL;
            flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );

    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );

    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

    output( head3 );
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void multiplication( NODE *p1, NODE *p2 , NODE * p3 ){
    NODE *current_1 = p1->next;
    NODE *current_2 = p2->next;

    // 遍历第一个多项式的每一项
    while (current_1 != NULL) {
        if (current_1->coef != 0) { // 忽略系数为0的项
            current_2 = p2->next;
            // 遍历第二个多项式的每一项
            while (current_2 != NULL) {
                if (current_2->coef != 0) { // 忽略系数为0的项
                    int coef_3p = current_1->coef * current_2->coef;
                    int exp_3p = current_1->exp + current_2->exp;

                    // 在结果多项式中找到相同指数的项
                    NODE *p = p3;
                    while (p->next != NULL && p->next->exp < exp_3p) {
                        p = p->next;
                    }

                    if (p->next != NULL && p->next->exp == exp_3p) {
                        p->next->coef += coef_3p;
                    } else {
                        NODE *new_node = (NODE *)malloc(sizeof(NODE));
                        new_node->coef = coef_3p;
                        new_node->exp = exp_3p;
                        new_node->next = p->next;
                        p->next = new_node;
                    }
                }
                current_2 = current_2->next;
            }
        }
        current_1 = current_1->next;
    }

    // 删除结果链表中系数为0的节点
    NODE *prev = p3;
    NODE *current_3 = p3->next;
    while (current_3 != NULL) {
        if (current_3->coef == 0) {
            prev->next = current_3->next;
            free(current_3);
            current_3 = prev->next;
        } else {
            prev = current_3;
            current_3 = current_3->next;
        }
    }

    // 如果结果多项式是零多项式，添加<0,0>
    if (p3->next == NULL) {
        p3->next = (NODE *)malloc(sizeof(NODE));
        p3->next->coef = 0;
        p3->next->exp = 0;
        p3->next->next = NULL;
    }
}

/* AC Version
void multiplication(NODE *head1, NODE *head2, NODE *head3)    
{    
    NODE *p1, *p2, *p3,*p3_pre, *pnew, *start;    
    int flag = 0;  
    p1=head1->next;    
    while(p1)    
    {    
        p2=head2->next;    
        int c1;    
        c1=p1->coef;    
        if(c1==0)    
        {    
            p1=p1->next;    
            continue;    
        }    
        start=head3;    
        while(p2)    
        {    
            flag=0;    
            pnew=(NODE *)malloc(sizeof(NODE));    
            int c,e;    
            c=p2->coef*p1->coef;    
            e=p2->exp+p1->exp;    
            pnew->coef=c;    
            pnew->exp=e;    
            int c2;    
            c2=p2->coef;    
            if(c2==0)    
            {    
                p2 = p2->next;    
                continue;    
            }    
            p3=start->next;    
            p3_pre=start;    
            while((p3)&&(p3->exp<e))    
            {    
                p3=p3->next;    
                p3_pre=p3_pre->next;    
            }    
            if(!p3)    
            {    
                p3_pre->next=pnew;    
                pnew->next=NULL;    
                start=p3_pre;    
            }    
            else if(p3->exp==e)    
            {    
                p3->coef=c+p3->coef;;    
                start=p3_pre;    
            }    
            else if(p3->exp>e)    
            {    
                p3_pre->next=pnew;    
                pnew->next=p3;    
                start=p3_pre;    
            }    
            p2=p2->next;    
        }    
        p1=p1->next;    
    }    
    if(head3->next==NULL)    
    {    
        printf("<0,0>,");    
    }    
    NODE *tmp;    
    p3=head3;    
    while(p3)     
    {       
        if(p3->coef==0&&p3->exp!=0)    
        {     
            p3=tmp;     
            p3->next=p3->next->next;      
            p3=p3->next;     
        }     
        else    
        {       
         tmp=p3;     
         p3=p3->next;     
        }     
    }
}
*/
