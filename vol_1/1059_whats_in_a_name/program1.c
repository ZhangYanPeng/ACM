#include <stdio.h>
int strechroad(int match[][3],int *msl,int *msr,int len,int *road,int lr,int type){
  int i,j;
  if(!type && !msr[road[lr-1]]){
    for(i=0;i<lr-1;i++){
      if(i%2){
	for(j=0;j<len;j++){
	  if(match[j][0]==road[i+1]&&match[j][1]==road[i])
	    match[j][2]=0;
	}
      }
      else{
	for(j=0;j<len;j++){
	  if(match[j][0]==road[i]&&match[j][1]==road[i+1])
	    match[j][2]=1;
	}
      }
    }
    msl[road[0]]=1;
    msr[road[lr-1]]=1;
    return 1;
  }
  if(type && !msl[road[lr-1]]){
    for(i=0;i<lr-1;i++){
      if(i%2){
	for(j=0;j<len;j++){
	  if(match[j][0]==road[i]&&match[j][1]==road[i+1])
	    match[j][2]=0;
	}
      }
      else{
	for(j=0;j<len;j++){
	  if(match[j][0]==road[i+1]&&match[j][1]==road[i])
	    match[j][2]=1;
	}
      }
    }
    msl[road[lr-1]]=1;
    msr[road[0]]=1;
    return 1;
  }
  for(i=0;i<len;i++){
    if(!type){
      if(match[i][2]==1&&match[i][1]==road[lr-1]){
	for(j=0;j<len;j++){
	  if(!match[j][2]&&match[j][0]==match[i][0]){
	    road[lr]=match[j][0];
	    road[lr+1]=match[j][1];
	    lr+=2;
	    match[j][2]=2;
	    match[i][2]=2;
	    if( strechroad(match,msl,msr,len,road,lr,type) ){
	      return 1;
	    }
	    match[i][2]=1;
	    match[j][2]=0;
	    lr-=2;
	  }
	}
      }
    }
    else{
      if(match[i][2]==1&&match[i][0]==road[lr-1]){
	for(j=0;j<len;j++){
	  if(!match[j][2]&&match[j][1]==match[i][1]){
	    road[lr]=match[j][1];
	    road[lr+1]=match[j][0];
	    lr+=2;
	    match[j][2]=2;
	    match[i][2]=2;
	    if( strechroad(match,msl,msr,len,road,lr,type) ){
	      return 1;
	    }
	    match[j][2]=0;
	    match[i][2]=1;
	    lr-=2;
	  }
	}
      }
    }
  }
  return 0;
}
int max_match(int op[20][20],int n){
  int match[400][3];
  int msl[20],msr[20];
  int len=0;
  int i,j;
  int check;
  int road[20];
  int sum;
  for(i=0;i<n;i++){
    msl[i]=0;
    msr[i]=0;
    for(j=0;j<n;j++){
      if(op[i][j]){
        match[len][0]=i;
	match[len][1]=j;
	match[len][2]=0;
	len++;
      }
    }
  }
  check=1;
  while(check){
    check=0;
    for(i=0;i<len;i++){
      if(!match[i][2]&&!msl[match[i][0]]){
	road[0]=match[i][0];
	road[1]=match[i][1];
	match[i][2]=2;
	if(strechroad(match,msl,msr,len,road,2,0))
	  check++;
	else
	  match[i][2]=0;
      }
      if(!match[i][2]&&!msr[match[i][1]]){
	road[0]=match[i][1];
	road[1]=match[i][0];
	match[i][2]=2;
	if(strechroad(match,msl,msr,len,road,2,1))
	  check++;
	else
	  match[i][2]=0;
      }
    }
  }
  sum=0;
  for(i=0;i<n;i++){
    if(msl[i])
      sum++;
  }
  return sum;
}

int main(){
  int num;
  int n;
  char id[20][21];
  char str[20][21];
  char tmpstr[21];
  int tmpop;
  int op[20][20];
  int i,j,k;
  char log[23];
  int idst[20];
  int st;
  int check;
  int pos;
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
    for(i=0;i<n;i++){
      for(j=0;j<n-i-1;j++){
	if(strcmp(str[j],str[j+1])>0){
	  strcpy(tmpstr,str[j]);
	  strcpy(str[j],str[j+1]);
	  strcpy(str[j+1],tmpstr);
	  for(k=0;k<20;k++){
	    tmpop=op[j][k];
	    op[j][k]=op[j+1][k];
	    op[j+1][k]=tmpop;
	  }
	}
      }
    }

    for(i=0;i<n;i++){
      printf("%s:",str[i]);
      check=0;
      for(j=0;j<n;j++){
	if(op[i][j]){
	  op[i][j]=0;
	  if(max_match(op,n)<n){
	    printf("%s\n",id[j]);
	    check=1;
	    op[i][j]=1;
	    break;
	  }
	  op[i][j]=1;
	}
      }
      if(!check)
	printf("???\n");
    }
    if(num)
      printf("\n");
  }
  return 0;
}
