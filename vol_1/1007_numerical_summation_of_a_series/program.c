#include <stdio.h>
#include <math.h>
int main(){
  double x=0.000;
  double sum = 0.000;
  double k;
  double i;
  for(i =0;i <2001;i++)
    {
      sum = 0.000;
      for(k=1;k <10000;k++)
	sum = sum + 1/(k*(k+1)*(k+2)*(k+x));
      sum = (1-x)*((2-x)*sum + 0.25) +1;
      printf("%5.3f %16.12f\n", x,sum ); 
      x = x + 0.001;
    }
  return 0;
}
