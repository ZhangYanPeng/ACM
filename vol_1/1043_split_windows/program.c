#include <stdio.h>
int pos;
char tree[1000];
struct node{
  struct node *left, *right;
  char c;
  char *pic;
  int height,width;
};


struct node* construct_tree(){
  struct node* root = (struct node*)malloc(sizeof(struct node));
  int i,j;
  root->c=tree[pos];
  pos++;
  if(root->c>='A'&&root->c<='Z'){
    root->left=NULL;
    root->right=NULL;
    root->height=2;
    root->width=2;
    root->pic = (char*)malloc(sizeof(char)*10);
    root->pic[0][0]=root->c;
    root->pic[0][1]=root->'-';
    root->pic[0][2]=root->'*';
    root->pic[1][0]=root->'|';
    root->pic[1][1]=root->' ';
    root->pic[1][2]=root->'|';
    root->pic[2][0]=root->'*';
    root->pic[2][1]=root->'-';
    root->pic[2][2]=root->'*';
    return root;
  }
  else{
    root->left==construct_tree();
    root->right==construct_tree();
    if(root->c == '-'){
      if(left->width!=right->width){
	if(left->width<right->width)
	  strech(left,right->width,left->height);
	else
	  strech(right,left->width,right->height);
      }
      pic = (char*)malloc(sizeof(char*))
      for(i=left->height;i>=0;i--)
	for(j=0;j<=left->width;j++){
	  pic[i][j]=left->pic[i][j];
	  pic[i+left->height][j]=right->pic[i][j];
	}
    }
    else if(root->c == '|'){
      if(left->height!=right->height){
	if(left->height<right->height)
	  strech(left,left->width,right->height);
	else
	  strech(right,right->width,left->height);
      }
      
    }
  }
  
  return NULL;
}

void destroy_tree(struct node *p){
  if(p){
    if(p->left)
      destroy_tree(p->left);
    if(p->right)
      destroy_tree(p->right);
    free(p);
  }
  return;
}

int main(){
  int n;
  struct node* tr;
  scanf("%d",&n);
  while(n>0){
    n--;
    scanf("%s",tree);
    tr = construct_tree();

    destroy_tree(tr);
  }
  return 0;
}
