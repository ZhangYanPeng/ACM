#include <iostream>
using namespace std;

void swap_job(int* a, int* b){
    int t[7];
    for(int i=0;i<7;i++){
        t[i]=a[i];
        a[i]=b[i];
        b[i]=t[i];
    }
}
int main(){
    int num=0;
    while(1){
        num++;
        int timeline;
        cin>>timeline;
        if(!timeline)
            break;
        int cpu,mem,jnum;
        cin>>cpu>>mem>>jnum;
        int job[10000][7];
        for(int i=0;i<jnum;i++){
            cin>>job[i][0]>>job[i][1]>>job[i][2]>>job[i][3]>>job[i][4]>>job[i][5]>>job[i][6];
        }
        for(int i=0;i<jnum;i++){
            int check=0;
            for(int j=0;j<jnum-i-1;j++){
                if( job[j][2]>job[j+1][2] || (job[j][2]==job[j+1][2] && job[j][3]<job[j+1][3] ) ){
                    swap_job(job[j],job[j+1]);
                    check++;
                }
            }
            if(!check)
                break;
        }
        int income=0;
        int qs=0,qe=0;
        for(int i=0;i<timeline;i++){
            while(job[qe][2]==i&&qe<jnum)
                qe++;
            int ct=cpu,mt=mem;
            for(int j=qs;j<qe;j++){
                if(ct>=job[j][0]&&mt>=job[j][1]){
                    ct-=job[j][0];
                    mt-=job[j][1];
                    for(int k=j;k>qs;k--)
                        swap(job[k],job[k-1]);
                    income += job[qs][4];
                    if(i+1 < job[qs][3]){
                        income += job[qs][5]*(job[qs][3]-i-1);
                    }
                    else if(i+1> job[qs][3]){
                        income += job[qs][6]*(job[qs][3]-i-1);
                    }
                    qs++;
                }
            }
        }
        for(int i=qs;i<qe;i++){
            if(job[i][3]<timeline){
                income += job[i][6]*(job[i][3]-timeline);
            }
        }

        cout<<"Case "<<num<<": ";
        cout<<income<<endl;
        cout<<endl;
    }
    return 0;
}
