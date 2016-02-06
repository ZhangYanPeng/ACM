#include <stdio.h>
char encry[30][5]={{".-"},{"-..."},{"-.-."},{"-.."},{"."},{"..-."},{"--."},
		   {"...."},{".."},{".---"},{"-.-"},{".-.."},{"--"},{"-."},
		   {"---"},{".--."},{"--.-"},{".-."},{"..."},{"-"},{"..-"},
		   {"...-"},{".--"},{"-..-"},{"-.--"},{"--.."},{"..--"},
		   {".-.-"},{"---."},{"----"}};
int tran(char c){
  if(c>='A'&&c<='Z')
    return c-'A';
  switch(c){
  case '_':return 26;
  case ',':return 27;
  case '.':return 28;
  case '?':return 29;
  }
  return -1;
}

char retran(int t){
  if(t<26)
    return t+'A';
  switch(t){
  case 26:return'_';
  case 27:return',';
  case 28:return'.';
  case 29:return'?';
  }
  return 0;
}
int main(){
  char cry[101];
  char str[401];
  int len[100];
  int n;
  int tmp,i,j;
  int num;
  int pn,pc;
  int check;
  int tn=0;
  scanf("%d",&n);
  while(n--){
    scanf("%s",cry);
    pc=0;
    pn=0;
    while(cry[pc]){
      tmp=tran(cry[pc]);
      i=0;
      while(encry[tmp][i]){
	str[pn]=encry[tmp][i];
	i++;
	pn++;
      }
      len[pc]=i;
      pc++;
    }
    str[pn]=0;
    i=0;
    pc--;
    while(i<pc){
      tmp = len[pc];
      len[pc] = len[i];
      len[i] = tmp;
      i++;
      pc--;
    }
    pc=0;
    pn=0;
    while(str[pc]){
      for(i=0;i<30;i++){
	check=1;
	for(j=0;j<len[pn];j++){
	  if(str[pc+j]!=encry[i][j]){
	    check=0;
	    break;
	  }
	}
	if(encry[i][j])
	  check=0;
	if(check)
	  break;
      }
      cry[pn] = retran(i);
      pc+= len[pn];
      pn++;
    }
    tn++;
    printf("%d: %s\n",tn,cry);
  }
  return 0;
}
