#include <stdio.h>

int set_n;
int cost[20];
long cust_f[20];
int val[20];
int min_cost,max_cost,fea_n,cus_n;
int cus_fn;
double profit;
long best_product;
int best_profit;
int best_cost;
int best_pf;
int best_fn;
int best_cn;

void max_profit(long product,int co, int fn){
  long i;
  int tp,tc,tf,tcn,pf;
  double tpf=0;
  int check;
  if(co>max_cost)
    return;
  else if(co>=min_cost){
    tf=0;
    tcn=0;
    for(i=0;i<cus_n;i++){
      if( (cust_f[i]|product) == product ){
	tf += val[i];
	tcn++;
      }
    }
    tpf = ((double)tf)/((double)co);
    pf = tf - co;
    check =0;
    if(tpf>profit)
      check=1;
    else if(tpf == profit){
      if(pf>best_pf)
	check=1;
      else if(pf == best_pf){
	if(fn<best_fn)
	  check=1;
	else if(fn==best_fn){
	  if(tcn>best_cn)
	    check=1;
	}
      }
    }
    if(check){
      profit = tpf;
      best_profit = tf;
      best_product = product;
      best_cost = co;
      best_pf = pf;
      best_fn = fn;
      best_cn = tcn;
    }
  }
  for(i=fea_n;i>0;i--){
    if( (product>>(i-1)) & 1 )
      break;
    else{
      tp = product|( ((long)1) << (i-1) );
      tc = co+cost[i-1];
      max_profit(tp,tc,fn+1);
    }
  }
}

int main(){
  int i,j,k,t;
  int check;
  scanf("%d",&set_n);
  for(i=0;i<set_n;i++){
    scanf("%d %d %d %d",&min_cost,&max_cost,&fea_n,&cus_n);
    for(j=0;j<fea_n;j++)
      scanf("%d",&cost[j]);
    for(j=0;j<cus_n;j++){
      scanf("%d",&cus_fn);
      cust_f[j]=0;
      for(k=0;k<cus_fn;k++){
	scanf("%d",&t);
	cust_f[j] = cust_f[j] | (1<<(t-1));
      }
      scanf("%d",&val[j]);
    }
    profit=-1000000;
    best_product=0;
    best_profit=-1000000;
    best_cost=1000000;
    best_pf=-1000000;
    best_fn=0;
    best_cn=0;
    max_profit(0,0,0);

    if(i)
      printf("\n");
    printf("Feature Set %d\n",i+1);
    printf("%.3f\n%d\n%d\n",profit,best_profit,best_cost);
    
    check = 1;
    for(j=0;j<fea_n;j++){
      if(best_product>>j&1){
	if(!check)
	  printf(" ");
	else
	  check=0;
	printf("%d",j+1);
      }
    }
    printf("\n");
    check = 1;
    for(j=0;j<cus_n;j++){
      if( (best_product|cust_f[j]) == best_product ){
	if(!check)
	  printf(" ");
	else
	  check=0;
	printf("%d",j+1);
      }
    }
  }
  return 0;
}
