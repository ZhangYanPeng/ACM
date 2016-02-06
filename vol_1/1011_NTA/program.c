#include <stdio.h>
#include <math.h>
struct node{
  struct node* next;
  int tran[2];
};
char tree[3000];
int level;
int m,n,k;
struct node* tr[15][10];

struct node* createlist(){
  struct node* p = NULL;
  return p;
}
void deletelist(struct node* p){
  struct node* tmp;
  while(p){
    tmp = p;
    p = p->next;
    free(tmp);
  }
  return;
}
struct node* addlist(struct node* p, int a, int b){
  struct node* pt = p;
  struct node* pn = (struct node*)malloc(sizeof(struct node));
  pn->next = NULL;
  pn->tran[0]=a;
  pn->tran[1]=b;
  if(p){
    while(p->next)
      p=p->next;
    p->next = pn;
    return pt;
  }
  else 
    return pn;
}

int get_left(int i){
  return 2*i+1; 
}

void getaclist(int* ac, int* l, int* r, char c){
  int i,j;
  struct node* p;
  int check;
  for(i=0;i<n;i++){
    check=0;
    p=tr[i][c-'a'];
    while(p){
      check=0;
      for(j=0;j<n;j++){
	if(l[tran[0]]){
	  check=1;
	  break;
	}
      }
      if(check){
	check=0;
	for(j=0;j<n;j++){
	  if(r[tran[1]]){
	    check=1;
	    break;
	  }
	}
      }
      if(check)
	break;
      p = p->next;
    }
    ac[i]=check;
  }
  return;
}

void getac(int* ac,int pos){
  int acl[15],acr[15];
  int i;
  if(tree[pos]=='*'){
    for(i=0;i<n;i++){
      if(i>=(n-m))
	ac[i]=1;
      else 
	ac[i]=0;
    }
  }
  else if( pos < ((int)pow(2,level)-1) ){
    getac(acl,2*pos+1);
    getac(acr,2*pos+2);
    getaclist(ac,acl,acr,tree[pos]);
  } 
  else{
    for(i=0;i<n;i++){
      if(i>=(n-m)){
	acl[i]=1;
	acr[i]=1;
      }
      else{
	acl[i]=0;
	acr[i]=0;
      }
    }
    getaclist(ac,acl,acr,tree[pos]);
  }
  return;
} 

void do_buf(char* buf){
  int i=0;
  do{
    buf[i] = buf[i+4];
    i++;
  }while(buf[i]);
}

int main(){
  int i,j;
  int ac[15];
  char buf[1000];
  int st;
  char c;
  int a,b;
  int num=0;
  int check;
  while(1){
    num++;
    scanf("%d %d %d",&n,&m,&k);
    if(!m&&!n&&!k)
      break;
    if(num>1)
      printf("\n");
    printf("NTA%d:\n",num);
    gets(buf);
    for(i=0;i<n;i++){
      for(j=0;j<k;j++){
	tr[i][j] = createlist();
	gets(buf);
	if(buf[0]){
	  while(1){
	    sscanf(buf,"%d %d",&a,&b);
	    do_buf(buf);
	    tr[i][j]=addlist(tr[i][j],a,b);
	    if(buf[0]){
	      break;
	      return 0;
	    }
	  }
	}
      }
    }

    while(1){
      scanf("%d",&level);
      if(level<0)
	break;
      for(i=0;i<((int)pow(2,level+1)-1);i++){
	while(1){
	  scanf("%c",&c);
	  if('a'<=c && c<='z' || c=='*'){
	    tree[i]=c;
	    break;
	  }
	}
      }
      
      getac(ac,0);
      check=0;
      for(i=0;i<n;i++){
	if(ac[i]){
	  printf("Valid\n");
	  check=1;
	  break;
	}
      }
      if(!check)
	printf("Invalid\n");
    }
    for(i=0;i<n;i++)
      for(j=0;j<k;j++)
	free(tr[i][j]);
  }
  return 0;
}
