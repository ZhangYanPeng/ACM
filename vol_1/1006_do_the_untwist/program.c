#include <stdio.h>

int main(){
  int key;
  char code[300],cip[300],plain[300];
  int l;
  int i;

  while(1){
    scanf("%d",&key);
    if(!key)
      break;
    scanf(" %s",code);
    l=0;
    while(code[l]!='\0'){
      switch(code[l]){
      case '_': cip[l]=0;break;
      case '.': cip[l]=27;break;
      default : cip[l]=code[l]-96;break;
      }
      l++;
    }
    for(i=0;i<l;i++){
      plain[(key*i)%l]=(cip[i]+i)%28;
      switch(plain[(key*i)%l]){
      case 0: code[(key*i)%l]='_';break;
      case 27: code[(key*i)%l]='.';break;
      default : code[(key*i)%l]=plain[(key*i)%l]+96;break;
      }
    }
    printf("%s\n",code);
  }
  return 0;
}
