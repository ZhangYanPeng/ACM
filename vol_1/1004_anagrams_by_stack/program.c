#include <stdio.h>

void op(char* s, char* s_aim, char* stack, char* o, int l, int deep, int pos, int pos_aim,int op_num){
  char stack_bake[100];
  int i;
  if(!deep && pos>=l){
    i=0;
    while(o[i]){
      printf("%c ",o[i]);
      i++;
    }
    printf("\n");
    return;
  }
  for(i=0;i<100;i++)
    stack_bake[i]=stack[i];
  if(pos<l){
    o[op_num]='i';
    stack[deep]=s[pos];
    op(s,s_aim,stack,o,l,deep+1,pos+1,pos_aim,op_num+1);
  }
  if(deep && s_aim[pos_aim]==stack[deep-1]){
    o[op_num]='o';
    op(s,s_aim,stack_bake,o,l,deep-1,pos,pos_aim+1,op_num+1);
  }
  return;
}

int main(){
  char s[100]={0};
  char s_aim[100]={0};
  char stack[100]={0};
  char o[200]={0};
  int l=0;
  int tmp;

  while(scanf("%s",s)!=EOF){
    scanf("%s",s_aim);
    for(l=0;l<200;l++)
      o[l]=0;
    l=0;
    tmp=0;
    while(s[l]!='\0')
      l++;
    while(s_aim[tmp]!='\0')
      tmp++;
    printf("[\n");
    if(tmp==l)
      op(s,s_aim,stack,o,l,0,0,0,0);
    printf("]\n");
  }
  return 0;
}
