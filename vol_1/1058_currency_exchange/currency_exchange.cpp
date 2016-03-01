#include <iostream>
#include <iomanip>
using namespace std;
double exchange(double amount, double ex){
	amount *= ex;
	int tmp = (int)(amount*1000);
	int t = tmp/10;	
	if(tmp%10>=5){
		t++;
	}
	double re = (double)t/100.0;
	return re;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		double ex[5][5];
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				cin>>ex[i][j];
		while(1){
			int trip[10];
			int len;
			cin>>len;
			if(!len)
				break;
			trip[0]=1;
			trip[len+1]=1;
			for(int i=0;i<len;i++)
				cin>>trip[i+1];
			double amount;
			cin>>amount;
			for(int i=0;i<=len;i++){
				amount=exchange(amount,ex[trip[i]-1][trip[i+1]-1]);
			}
			cout<<fixed<<setprecision(2)<<amount<<endl;
		}
		if(n>1)
			cout<<endl;
	}
	return 0;
}