#include <stdio.h>
#include <math.h>
int main(){
  int ne;
  int n;
  int i,j,k,r;
  int encry[3][26];
  char c[10000];
  int testn;
  int count;
  int tmp;
  ne=1;
  while(1){
    scanf("%d",&n);
    if(!n)
      break;
    if(ne!=1)
      printf("\n\n");
    printf("Enigma %d:",ne);
    for(i=0;i<3;i++){
      scanf("%s",c);
      for(j=0;j<n;j++){
	encry[i][j] = c[j]-'A'-j;
      }
    }
    scanf("%d",&testn);
    for(i=0;i<testn;i++){
      count=0;
      printf("\n");
      scanf("%s",c);
      j=0;
      while(c[j]!='\0'){
	for(k=2;k>=0;k--){
	  tmp=count/(pow(n,k));
	  tmp=tmp%n;
	  for(r=0;r<n;r++){
	    if(c[j] == ((r+encry[k][(r-tmp+n)%n]+n)%n+'A')){
	      c[j] = 'A'+ r;
	      if(k==0)
		c[j] += 'a'-'A';
	      break;
	    }
	  }
	}
	count++;
	j++;
      }
      printf("%s",c);
    }
    ne++;
  }
  return 0;
}
