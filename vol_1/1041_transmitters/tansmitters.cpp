#include <iostream>
using namespace std;

int main(){
	while(1){
		int x,y;
		double r;
		cin>>x>>y>>r;
		if(r<=0)
			break;
		int n;
		cin>>n;
		double points[150][3];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>points[sum][0]>>points[sum][1];
			points[sum][0] -= x;
			points[sum][1] -= y;
			if( points[sum][0]*points[sum][0]+points[sum][1]*points[sum][1] <= r*r ){
				points[sum][2]=0;
				sum++;
			}
		}
		int max=0;
		for(int i=0;i<sum;i++){
			for(int j=i;j<sum;j++){
				if(j==i){
					points[i][2]++;
					continue;
				}
				int t = points[i][0]*points[j][1] - points[j][0]*points[i][1];
				if(t>=0)
					points[i][2]++;
				if(t<=0)
					points[j][2]++;
			}
			max = max>points[i][2]?max:points[i][2];
		}
		cout<<max<<endl;
	}
	return 0;
}