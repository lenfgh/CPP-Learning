/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <iostream>  
using namespace std;  
int main(int argc, char** argv)  
{  
    int n, m;  
    int count(int, int);  
    cin >> n >> m;  
    cout << count(n, m) << endl;  
    return 0;  
}  

int count( int n, int m ) {
    if(1==n&&1==m) return 1;
    else if(1>n||1>m) return 0;
    else if(n < m) return count(n,n);
    else if(n==m) return count(n,m-1)+1;
    else return count(n-m,m)+count(n,m-1);
} 
  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  