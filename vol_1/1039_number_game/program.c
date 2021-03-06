#include <stdio.h>
int dp[1<<19+1];
int set(int a,int i){
  int j;
  int k,t;
  a&=~(1<<(i-2));
  for(j=i+2;j<21;j++){
    if( 1&(a>>(j-2)) ){
      t=(1&(a>>(j-i-2)));
      if( !t ){
	a&=~(1<<(j-2));
      }
    }
  }
  return a;
}

int juge(int a){
  int i,k;
  int tmp;
  if(dp[a]>=0){
    return dp[a];
  }
  for(i=2;i<21;i++){
    if( 1&(a>>(i-2)) ){
      tmp=set(a,i);
      if(juge(tmp)){
	dp[a]=0;
	return 0;
      }
    }
  }
  dp[a]=1;
  return 1;
}

int main(){
  int state=0;
  int tmp;
  int w[21];
  int n,m,t;
  int i,j,check;
  for(i=0;i<(1<<19+1);i++)
    dp[i]=-1;
  dp[0]=1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Scenario #%d:\n",i+1);
    scanf("%d",&m);
    check=0;
    state=0;
    for(j=0;j<21;j++)
      w[j]=0;
    for(j=0;j<m;j++){
      scanf("%d",&t);
      state=state|(1<<t-2);
    }
    for(j=2;j<21;j++){
      if( 1&(state>>(j-2)) ){
	tmp=set(state,j);
	if(juge(tmp)){
	  w[j]=1;
	  check++;
	}
      }
    }
    if(check){
      printf("The winning moves are:");
      for(j=2;j<21;j++){
	if(w[j])
	  printf(" %d",j);
      }
      printf(".\n");
    }
    else
      printf("There is no winning move.\n");
    printf("\n");
  }
  return 0;
}
