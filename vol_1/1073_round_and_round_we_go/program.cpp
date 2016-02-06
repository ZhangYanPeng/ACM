#include <iostream>
using namespace std;

void plu(int *re, int *a,int len){
	for(int i=len-1;i>=0;i--){
		re[i] += a[i];
		if(i){
			re[i-1]+=re[i]/10;
		}
		re[i]=re[i]%10;
	}
}
int comp(int *a, int *b, int len){
	for(int i=0;i<len;i++){
		if(b[i]-a[i])
			return 0;
	}
	return 1;
}

int main(){
	string str;
	while(cin>>str){
		int rq[120];
		int a[60];
		int len = str.length();
		int i=0;
		while(str[i]){
			rq[len+i]=a[i]=rq[i]=str[i]-'0';
			i++;
		}
		int check;
		for(i=1;i<len;i++){
			check=0;
			plu(a,rq,len);
			for(int j=0;j<len;j++){
				if(comp(a,&rq[j],len)){
					check++;
					break;
				}
			}
			if(!check)
				break;
		}
		if(check)
			cout<<str<<" is cyclic"<<endl;
		else
			cout<<str<<" is not cyclic"<<endl;
	}
	return 0;
}