#include<stdio.h>
int main(){
  float c;
  float result=0;
  int s;
  while(1){
    scanf("%f",&c);
    if(c==0)
      break;
    result=0;
    s=2;
    while(result<c)
      {
	result=result+1.00f/s;
	s++;
      }
    printf("%d card(s)\n",s-2);
  }
  return 0;
}
