#include <stdio.h>
int jptonext(char * exp,int i){
  while(exp[i]){
    if(exp[i]=='(')
      i=jptonext(exp,i+1);
    if(exp[i]==')')
      break;
    i++;
  }
  i++;
  return i;
}
char getop(char* exp){
  int level=4;
  int p;
  p=0;
  while(exp[p]){
    switch(exp[p]){
    case '+':level=0;p++;break;
    case '*':level=(level>0)?1:level;p++;break;
    case '^':level=(level>1)?2:level;p++;break;
    case '(':
      {
	level=(level>2)?3:level;
	p=jptonext(exp,p+1);
	break;
      }
    default :p++;break;
    }
  }
  switch(level){
  case 0:return '+';
  case 1:return '*';
  case 2:return '^';
  case 3:return '(';
  }
}

int main(){
  char expression[10000];
  int n;
  int opn;
  char level;
  char c;
  char tmp[10000];
  char tmp1[10000];
  int i,s,l,t;
  char op[10000];
  int num=0;
  while(1){
    scanf("%s",expression);
    if(expression[0]=='*')
      break;
    if(num){
      printf("\n");
    }
    num++;
    scanf("%d",&n);
    i=0;
    while(expression[i]<='z'&&expression[i]>='a')
      i++;
    strncpy(tmp1,expression,i);
    tmp1[i]='\0';
    printf("Expression %s:\n",tmp1);
    while(n--){
      i=0;
      while(expression[i]<='z'&&expression[i]>='a')
	i++;
      strncpy(op,expression,i);
      op[i]='\0';
      strcpy(tmp,expression+i+2);
      while(1){
	scanf("%d%c",&opn,&c);
	sprintf(tmp1,"op(%d,",opn);
	strcat(tmp1,op);
	strcat(tmp1,")");
	strcpy(op,tmp1);
	level=getop(tmp);
	switch(level){
	case '(':
	  {
	    strcpy(tmp,tmp+1);
	    i=0;
	    while(tmp[i])
	      i++;
	    tmp[i-1]='\0';
	    break;
	  }
	default:
	  {
	    i=0;
	    while(opn){
	      s=i;
	      while(tmp[i]){
		if(tmp[i]=='('){
		  i=jptonext(tmp,i+1);
		}
		if(tmp[i]==level)
		  break;
		i++;
	      }
	      l=i-s;
	      i++;
	      opn--;
	    }
	    strncpy(tmp,tmp+s,l);
	    tmp[l]='\0';
	  }
	}
	if(c!=' ')
	  break;
      }
      strcat(op,"=");
      strcat(op,tmp);
      printf("%s\n",op);
    }
  }
  return 0;
}
