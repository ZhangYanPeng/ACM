#include <stdio.h>

int op[20][20];
int tmp[20][20];
int alts[20][20];

void fill(int n,int line){
  int i,j,check;
  if(line==n){
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
	alts[i][j]+=tmp[i][j];
    return;
  }
  for(i=0;i<n;i++){
    if(op[line][i]){
      check=1;
      for(j=0;j<line;j++)
	if(tmp[j][i])
	  check=0;
      if(check){
	tmp[line][i]=1;
	fill(n,line+1);
	tmp[line][i]=0;
      }
    }
  }
}

int main(){
  int num;
  int n;
  char id[20][21];
  char str[20][21];
  char ssort[20][21];
  char strt[21];
  int i,j,k,t;
  char log[23];
  int idst[20];
  int st;
  scanf("%d",&num);
  while(num--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%s",id[i]);   
    for(i=0;i<20;i++){
      idst[i]=0;
      for(j=0;j<20;j++)
	op[i][j]=1;
    }
    st=0;
    while(1){
      scanf("%s",log);
      if(log[0]=='Q')
	break;
      switch(log[0]){
      case 'E':{
	scanf("%s",log);  
	for(i=0;i<20;i++){
	  if(!strcmp(log,str[i]))
	    break;
	}
	if(i<20)
	  idst[i]=1;
	else{
	  strcpy(str[st],log);
	  idst[st]=1;
	}
	st++;
	break;
      }
      case 'L':{
	scanf("%s",log);
	for(i=0;i<20;i++){
	  if(!strcmp(log,str[i]))
	    break;
	}
	idst[i]=0;
	break;
      }
      case 'M':{
	scanf("%s",log);
	for(i=0;i<20;i++){
	  if(!strcmp(log,id[i]))
	    break;
	}
	for(j=0;j<20;j++)
	  op[j][i]=idst[j]&op[j][i];
	break;
      }
      }
    }
    
    for(i=0;i<n;i++)
      for(j=0;j<n;j++){
	alts[i][j]=0;
	tmp[i][j]=0;
      }
    fill(n,0);

    return;
    for(i=0;i<n;i++)
      strcpy(ssort[i],str[i]);
    for(i=0;i<n;i++){
      for(j=0;j<n-i-1;j++){
	if(strcmp(ssort[j],ssort[j+1])>=0){
	  strcpy(strt,ssort[j]);
	  strcpy(ssort[j],ssort[j+1]);
	  strcpy(ssort[j+1],strt);
	}
      }
    }
    for(i=0;i<n;i++){
      printf("%s:",ssort[i]);
      for(j=0;j<n;j++){
	if(!strcmp(str[j],ssort[i])){
	  break;
	}
      }
      t=0;
      for(k=0;k<n;k++){
	if(alts[j][k])
	  t++;
      }
      if(t==1){
	for(k=0;k<n;k++){
	  if(alts[j][k])
	    break;
	}
	printf("%s\n",id[k]);
      }
      else
	printf("???\n");
    }
    if(num)
      printf("\n");
  }
  return 0;
}
