#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char rc[33][22];
double dis[33][33];
char a[22],b[22];
int n,m;
int GetId(char s[])
{
    for(int i=1;i<=n;i++)
    if(strcmp(rc[i],s)==0)
     return i;
}
int main()
{
    int i,j,k;
    int t=1;
    double d;
    while(scanf("%d",&n)==1&&n)
    {
        for(i=1;i<=n;dis[i][i]=1,i++)
         for(j=1;j<=n;j++)
           dis[i][j]=0;
        for(i=1;i<=n;i++)
         scanf("%s",rc[i]);
        scanf("%d",&m);
        while(m--)
        {
           scanf("%s %lf %s",a,&d,b);
            i=GetId(a);
            j=GetId(b);
            dis[i][j]=d;
        }
      for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         if(dis[i][j]<dis[i][k]*dis[k][j])
          dis[i][j]=dis[i][k]*dis[k][j];
      bool f=0;
      for(i=1;i<=n;i++)
        if(dis[i][i]>1)
          {
              f=1;break;
          }
    printf("Case %d: ",t++);
    if(f) printf("Yes\n");else printf("No\n");

    }
    return 0;
}