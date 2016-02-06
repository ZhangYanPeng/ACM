#include <stdio.h>

int aTrue, bTrue; 
int judge(int m, int n, int p) 
{ 
    if(aTrue) return 0;
    if(m == 1 && n == 1) 
    {
        aTrue = 1; return 0; 
    }
    if(n == 1) bTrue = 1;  
    while(p > 1)
    {
        if(m%p == 0) judge(m/p, n, p-1);
        if(n%p == 0) judge(m, n/p, p-1);
        p--;
    }
    return 0;
}
   
int main()
{
    int a, b; 
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        if(a < b)   
            {int temp = a; a = b; b = temp;}    
        aTrue = 0; bTrue = 0;  
        judge(a, b, 100);
        if(!aTrue && bTrue)  
            printf("%d\n",b); 
        else
            printf("%d\n",a); 
    }
    return 0;
}
