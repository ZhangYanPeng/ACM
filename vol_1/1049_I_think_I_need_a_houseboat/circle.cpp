#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.1415926535897932384

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Property "<<i+1<<": This property will begin eroding in year ";
        double x,y,yt;
        cin>>x>>y;
        int year;
        yt = pi*(pow(x,2)+pow(y,2))/100;
        year = (int) yt+1;
        cout<<year<<"."<<endl;
    }
    cout<<"END OF OUTPUT.";
    return 0;
}
