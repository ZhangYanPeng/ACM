#include <iostream>
#include <iomanip>
#include <math.h>
#define pi 3.141592653589793
using namespace std;

int main(){
    double t[6];
    while(cin>>t[0]>>t[1]>>t[2]>>t[3]>>t[4]>>t[5]){
        double a,b,c;
        a=sqrt(pow(t[0]-t[2],2)+pow(t[1]-t[3],2));
        b=sqrt(pow(t[2]-t[4],2)+pow(t[3]-t[5],2));
        c=sqrt(pow(t[0]-t[4],2)+pow(t[1]-t[5],2));
        double p=(a+b+c)/2;
        cout<<fixed<<setprecision(2)<<a*b*c/2/sqrt(p*(p-a)*(p-b)*(p-c))*pi<<endl;
    }
    return 0;
}
