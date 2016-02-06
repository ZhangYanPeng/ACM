#include <stdio.h>

int main(){
  int n;
  int m;
  int check,t,st;
  int i;
  int tmp;
  while(1){
    scanf("%d",&n);
    if(!n)
      break;
    m=2;
    while(1){
      t=n;
      check=1;
      t--;
      st=0;
      while(check){
	if(t<2)
	  break;
	if((st+t)>=m){
	  tmp=st+t;
	  st = (tmp)%m;
	  t -= (tmp)/m;
	  if(st==(m-1)&&t>1){
	    check=0;
	    break;
	  }
	}
	else{
	  i=2;
	  while((st+i*t)<m)
	    i++;
	  if(((m-st)%t)==1){
	    check=0;
	    break;
	  }
	  else{
	    st = t-(m-st)%t;
	    if(st==t)
	      st=0;
	    t--;
	  }
	}
      }
      if(check){
	printf("%d\n",m);
	break;
      }
      m++;
    }
  }
  return 0;
}
