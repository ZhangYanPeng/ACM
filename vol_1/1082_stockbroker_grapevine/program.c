#include <stdio.h>

int main(){
  int i,j,k;
  int n;
  int t1,t2,t3;
  int cost[100][100];
  int check;
  while(1){
    scanf("%d",&n);
    if(!n)
      break;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
	cost[i][j]=1000;
      cost[i][i]=0;
    }
    for(i=0;i<n;i++){
      scanf("%d",&t1);
      for(j=0;j<t1;j++){
	scanf("%d%d",&t2,&t3);
	cost[i][t2-1]=t3;
      }
    }
    check=1;
    while(check){
      check=0;
      for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	  if(j!=i){
	    for(k=0;k<n;k++)
	      if( k!=i && k!=j && (cost[i][k]+cost[k][j])<cost[i][j]){
		cost[i][j]=cost[i][k]+cost[k][j];
		check=1;
	      }
	  }
	}
      }
    }
    t1=1000;
    t3=0;
    for(i=0;i<n;i++){
      t2=0;
      for(j=0;j<n;j++){
	if(cost[i][j]>t2)
	  t2=cost[i][j];
      }
      if(t1>t2){
	t1=t2;
	t3=i;
      }
    }
    if(t1==1000)
      printf("disjoint\n");
    else
      printf("%d %d\n",t3+1,t1);
  }
}
