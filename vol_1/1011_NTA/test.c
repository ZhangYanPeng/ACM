#include <stdio.h>

int main(){
  int i;
  int k;
  char c;
  char buf[1000];
  i=k=0;
  c='~';
  gets(buf);
  if(buf[0]){
    sscanf(buf,"%d %d%c",&i,&k,&c);
  }
  printf("%d %d %c",i,k,c);
}
