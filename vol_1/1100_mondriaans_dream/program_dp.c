#include <stdio.h>
#include <math.h>
int h,w;
long long fl[1024],cl[1024];

void dfs(int num,int re,int l){
  int tmp=num>>(l-1);
  int t;
  if(!l){
    cl[re]+=fl[num];
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
  int i,j;
  int l;
  while(1){
    scanf("%d %d",&h,&w);
    if(!h &&!w)
      break;
    if(h%2 &&w%2)
      printf("0\n");
    else{
      if(h<w){
	i=h;
	h=w;
	w=i;
      }
      for(i=0;i<pow(2,w);i++)
	cl[i]=0;
      cl[0]=1;
      for(i=0;i<=h;i++){
        for(j=0;j<pow(2,w);j++){
	  fl[j]=cl[j];
	  cl[j]=0;
	}
	for(j=0;j<pow(2,w);j++){
	  if(fl[j])
	    dfs(j,0,w);
	}
      }
      printf("%lld\n",cl[(int)pow(2,w)-1]);
    }
  }
  return 0;
}
