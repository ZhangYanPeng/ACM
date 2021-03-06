#include <stdio.h>
#include <math.h>
float p[1002][2];
int n;
int juge(int i){
  int a1,b1,c1,a2,b2,c2;
  int k;
  if(p[i][0]==p[i-1][0]&&p[i][1]==p[i-1][1])
    return 1;
  if(p[i][0]==p[i-1][0]){
    a1=1;
    b1=0;
    c1=-p[i][0];
  }
  else{
    b1=1;
    a1=(p[i-1][1]-p[i][1])/(p[i][0]-p[i-1][0]);
    c1=-a1*p[i][0]-b1*p[i][1];
  }
  if(i==n)
    k=1;
  else 
    k=0;
  for(;k<i-2;k++){
    if(p[k][0]==p[k+1][0]){
      a2=1;
      b2=0;
      c2=-p[k][0];
    }
    else{
      b2=1;
      a2=(p[k][1]-p[k+1][1])/(p[k+1][0]-p[k][0]);
      c2=-a1*p[k][0]-b1*p[k][1];
    }

    if(b2==b1 && a2==a1 && c1!=c2)
      return 0;
    else if(b2==b1 && a2==a1){
      if( ((p[k][0]-p[i][0])*(p[k][0]-p[i-1][0])<=0 || (p[k+1][0]-p[i][0])*(p[k+1][0]-p[i-1][0])<=0 || (p[i][0]-p[k][0])*(p[i][0]-p[k+1][0])<=0 || (p[i-1][0]-p[k][0])*(p[i-1][0]-p[k+1][0])<=0 && (p[k][0]-p[i][0])*(p[k][0]-p[i-1][0])<=0) || ((p[k+1][1]-p[i][1])*(p[k+1][1]-p[i-1][1])<=0 || (p[i][1]-p[k][1])*(p[i][1]-p[k+1][1])<=0 || (p[i-1][1]-p[k][1])*(p[i-1][1]-p[k+1][1])<=0)  )
	return 1;
    }
    if( (a1*p[k][0]+b1*p[k][1]+c1)*(a1*p[k+1][0]+b1*p[k+1][1]+c1)<=0 && (a2*p[i][0]+b2*p[i][1]+c2)*(a2*p[i-1][0]+b2*p[i-1][1]+c2)<=0 )
      return 1;
  }
  return 0;
}
int main(){
  int i;
  int num=0;
  float area;
  int check;
  while(1){
    num++;
    scanf("%d",&n);
    if(!n)
      break;
    
    if(num!=1)
      printf("\n");
    printf("Figure %d: ",num);

    check=1;
    for(i=0;i<=n;i++){
      if(i!=n)
	scanf("%f %f",&p[i][0],&p[i][1]);
      else{
	p[i][0]=p[0][0];
	p[i][1]=p[0][1];
      }
      if(check&&i>2){
	if(juge(i)){
	  check=0;
	}
      }
    }
    if(!check || n<=2){
      printf("Impossible\n");
    }
    else{
      area=0;
      for(i=0;i<n;i++){
	if(i==n-1){
	  area += (p[i][1]+p[0][1])/2*(p[0][0]-p[i][0]);
	}
	else{
	  area += (p[i][1]+p[i+1][1])/2*(p[i+1][0]-p[i][0]);
	}
      }
      printf("%.2f\n",area);
    }
  }
  return 0;
}
