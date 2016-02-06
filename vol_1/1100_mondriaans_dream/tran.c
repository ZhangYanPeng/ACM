#include <stdio.h>

void dfs(int num,int re,int l){
  int tmp=num>>(l-1);
  int t;
  if(!l){
    printf("::%d\n",re);
    return;
  }
  if( !(tmp&1) ){
    re=re<<1|1;
    l--;
    dfs(num,re,l);
  }
  else{
    t=re<<1;
    l--;
    dfs(num,t,l);
    tmp=num>>(l-1);
    if((tmp&1) && l ){
      t=re<<2|3;
      l--;
      dfs(num,t,l);
    }
  }
}

int main(){
  int k=6;
  int i,t;
  t=k;
  for(i=0;i<10;i++){
    printf("%d",t%2);
    t=t>>1;
  }
  printf("\n");
  dfs(0,0,2);
  return 0;
}
