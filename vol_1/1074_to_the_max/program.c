#include <stdio.h>

int main(){
  int rect[100][100];
  int tran[100];
  int max;
  int n;
  int i,j,k,p,tmp,ts;
  if(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
	scanf("%d",&rect[i][j]);
    }
    max=rect[0][0];
    for(i=0;i<n;i++){
      for(j=i;j<n;j++){
	for(p=0;p<n;p++){
	  tran[p]=0;
	  for(k=i;k<=j;k++){
	    tran[p]+=rect[p][k];
	  }
	}
	ts=0;
	for(k=0;k<n;k++){
	  if(ts>0)
	    ts+=tran[k];
	  else
	    ts = tran[k];
	  if(ts>max)
	    max=ts;
	}
      }
    }
    printf("%d\n",max);
  }
  return 0;
}
