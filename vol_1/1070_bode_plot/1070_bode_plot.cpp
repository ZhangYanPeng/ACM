#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
	float vs,r,c,f;
	int n;
	cin>>vs>>r>>c>>n;
	for(int i=0;i<n;i++){
		cin>>f;
		float vr = c*r*f*vs/sqrt(c*c*r*r*f*f+1);
		cout<<setprecision(3)<<std::fixed<<vr<<endl;
	}
	return 0;
}
