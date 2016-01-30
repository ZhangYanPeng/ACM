#include <iostream>
using namespace std;
int main(){
    int st[201],ed[201];
    int n;
    cin>>n;
    while(n--){
        for(int i=0;i<201;i++)
            st[i]=ed[i]=0;
        int num;
        cin>>num;
        while(num--){
            int t,t1;
            cin>>t>>t1;
            t=(t+1)/2;
            t1=(t1+1)/2;
            if(t>t1){
                int tmp=t;
                t=t1;
                t1=tmp;
            }
            st[t-1]++;
            ed[t1]++;
        }
        int max=0,count=0;
        for(int i=0;i<200;i++){
            count+=st[i];
            count-=ed[i];
            max = (max>count)? max:count;
        }
        cout<<max*10<<endl;
    }
    return 0;
}
