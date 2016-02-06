#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int p[20];
		int m;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		int s[20];
		for(int i=0;i<m;i++){
			s[i]=0;
		}
		for(int i=m-1;i>0;i--){
			int t=p[i]-p[i-1];
			int j=i;
			while(t--){
				while(s[j])
					j++;
				s[j]=j-i+1;
			};
		}
		s[0]=1;
		int j=1;
		while(j<m){
			if(!s[j])
				s[j]=j+1;
			j++;
		}
		for(int i=0;i<m;i++){
			if(i)
				cout<<" ";
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}