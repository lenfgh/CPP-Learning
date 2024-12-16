// This is the solution of the https://lexue.bit.edu.cn/mod/programming/view.php?id=469040
// created by Len Fu 12/16/2024
//

/* note :
   1. In the single direction nodelist, if you want to insert a node into it, you can only insert it behind the present
   node and cannot insert it into the before.
    2. The problem is that you should consider three ways to insert : 1. in the head 2. in the middle 3. in the last

 */

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <iostream>  
using namespace std;  
  
struct node  
{   int data;  
    struct node * next;  
};  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE );  
void sortlist( PNODE, int);  
  
int main( )  
{       int num=1;  
    PNODE head;  
    head = new NODE;  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )
    {
//        cout << "check 0" << endl;
        cin >> num;
        if ( num!=0 )  
            sortlist( head, num);
//        cout << "inputing" << endl;
//        cout << num << endl;
    }

    cout << "check" << endl;

    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   cout << p->data << endl;  
        p = p->next;  
    }  
};
  
//  This is an example for list. Please programme your code like it.

// ! Don't forget to delete the print check point.
void sortlist( PNODE h, int num ) 
{   

    PNODE p;
    p = new NODE;

    if(h->next == NULL) {
        p->data = num;
        p->next = NULL;
        h->next = p;
//        cout << 'a' << num << endl;
        return;   
    } else {
        p = h->next;
//        cout << 'b' << num << endl;
    }

    while(p != NULL) {
        
//        cout << p->data << endl;
//      cout << (p->next)->data << endl;
//      cout << num << endl;


        if(p->data == num) {
//            cout << "case 0" << endl;
            return;
        } else if (p->data > num) {
            PNODE newNode = new NODE;
            newNode->data = num;
            newNode->next = p;
            h->next = newNode;
//            cout << "case 1" << endl;
            return;
        }else if((p -> data < num) && (p->next)==NULL) {
            PNODE newNode = new NODE;
            newNode->data = num;
            newNode -> next = NULL;
            p -> next = newNode;
//            cout << "case 2" << endl;
            return;
        } else if ( (p->data < num ) && ((p->next)->data) > num ) {
            PNODE newNode = new NODE;
            newNode -> data = num;
            newNode -> next = p -> next;
            p -> next = newNode;
//            cout << "case 3" << endl;
            return;
        };

        p = p->next;
    };
};
  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  