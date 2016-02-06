#include <stdio.h>
int data[25][4];
int mark[10];
int top[10],bottom[10],left[10],right[10];
int fit(int state[25], int pos, int n){
  int l,r,k;
  if(pos%n){
    k = state[pos];
    l = data[k][3];
    k = state[pos-1];
    r = data[k][1];
    if(l!=r)
      return 0;
  }
  return 1;
}

int juge(int pos, int n, int state[25]){
  int i,j;
  int ma,st,ed;
  for(i=0;i<10;i++){
    if(top[i]<bottom[i])
      return 0;
    if(left[i]<right[i])
      return 0;
  }
  if(pos>=n*n)
    return 1;
  st = 0;
  ed = n*n;
  if(pos/n){
    ma = data[pos-n][2];
    st=mark[ma];
    ed=mark[ma+1];
  } 
  for(i=st;i<ed;i++){
    j=0;
    while(state[j]!=i && j<pos)
      j++;
    if(j<pos)
      continue;
    state[pos]=i;
    if( fit(state,pos,n) ){
      top[data[i][0]]--;
      left[data[i][3]]--;
      if(pos/n)
	bottom[data[i][0]]--;
      if((pos/n)!=(n-1))
	bottom[data[i][2]]++;
      if(pos%n)
	right[data[i][3]]--;
      if((pos%n)!=(n-1))
	right[data[i][1]]++;
      if( juge(pos+1,n,state) )
	return 1;
      top[data[i][0]]++;
      left[data[i][3]]++;
      if(!pos/n)
	bottom[data[i][0]]++;
      if((pos/n)!=(n-1))
	bottom[data[i][2]]--;
      if(!pos%n)
	right[data[i][3]]++;
      if((pos%n)!=(n-1))
	right[data[i][1]]--;
    }
  }
  return 0;
}

int main(){
  int n;
  int p,tmp;
  int k,j,c;
  int state[25]={0};
  int i=1;
  while(1){
    scanf("%d",&n);
    if(!n)
      break;
    for(k=0;k<n*n;k++)
      scanf("%d %d %d %d",&data[k][0],&data[k][1],&data[k][2],&data[k][3]);
    for(j=n*n-1;j>0;j--){
      c=0;
      for(k=0;k<j;k++){
	if(data[k][0]>data[k+1][0]){
	  for(p=0;p<4;p++){
	    tmp=data[k][p];
	    data[k][p]=data[k+1][p];
	    data[k+1][p]=tmp;
	  }
	  c++;
	}
      }
      if(!c)
	break;
    }
    k=0;
    for(j=0;j<10;j++){
      top[j]=bottom[j]=left[j]=right[j]=0;
      mark[j]=k;
      while(data[k][0]==j)
	k++;
    }
    for(j=0;j<n*n;j++){
      top[data[j][0]]++;
      left[data[j][3]]++;
    }
    if( juge(0,n,state) )
      printf("Game %d: Possible\n",i);
    else
      printf("Game %d: Impossible\n",i);
    i++;
  }
  return 0;
}
