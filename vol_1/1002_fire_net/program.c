#include <stdio.h>

int is_legal(int net[4][4],int n, int pos){
  int x,y;
  int i;
  x = pos/n;
  y = pos%n;
  if(net[x][y]>0)
    return 0;
  i=x;
  while(i>0){
    i--;
    if(net[i][y]==2)
      return 0;
    if(net[i][y]==1)
      break;
  }
  i=x;
  while(i<(n-1)){
    i++;
    if(net[i][y]==2)
      return 0;
    if(net[i][y]==1)
      break;
  }
  i=y;
  while(i>0){
    i--;
    if(net[x][i]==2)
      return 0;
    if(net[x][i]==1)
      break;
  }
  i=y;
  while(i<(n-1)){
    i++;
    if(net[x][i]==2)
      return 0;
    if(net[x][i]==1)
      break;
  }
  return 1;
}

int find_next(int net[4][4],int n, int pos, int *x, int *y){
  for(;pos<=(n*n-1);pos++){
    if(is_legal(net,n,pos)){
      *x = pos/n;
      *y = pos%n;
      return 1;
    }
  }
  return 0;
}

int get_most(int net[4][4], int n, int house[8][2], int l){
  int min_pos,x,y;
  int tmp;
  int max=0;
  int check=0;
  if(l==0)
    min_pos = 0;
  else
    min_pos = n*house[l-1][0] + house[l-1][1] + 1;

  while(min_pos<=(n*n-1) && find_next(net,n,min_pos,&x,&y)){

    check++;
    house[l][0]=x;
    house[l][1]=y;
    net[x][y]=2;
    tmp = get_most(net,n,house,l+1);
    max = (tmp>max)?tmp:max;
    net[x][y]=0;
    min_pos = n*x + y + 1;
  }

  if(check)
    return max+1;
  return 0;
}

int get_back(int net[4][4],int n,int house[8][2],int l){
  if(l==0)
    return 0;
  net[house[l-1][0]][net[l-1][1]]=0;
  return 1;
}

int main(){
  int net[4][4];
  int n;
  char s[5];
  int num=0;
  int l=0;
  int house_pos[8][2]={0};
  int i,j;
  while(1){
    num = 0;
    scanf("%d",&n);
    if(!n)
      break;
    for(i=0;i<n;i++){
      scanf("%s",s);
      for(j=0;j<n;j++)
	net[i][j] = (s[j]=='.')? 0:1;
    }

    num = get_most(net,n,house_pos,0);
    
    printf("%d\n",num);
  }
  return 0;
}
