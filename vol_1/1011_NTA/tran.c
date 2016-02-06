#include <stdio.h>
int tran(int *a){
  a[0]=2;
  a[1]=1;
}

int main(){
  int a[2];
  a[0]=1;
  a[1]=2;
  
  tran(a);
  printf("%d %d",a[0],a[1]);
  return 0;
}
