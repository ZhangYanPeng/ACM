#include <iostream>
using namespace std;
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int decom(int num, int* dr){
    for(int i=0;prime[i]<=num&&i<25;i++){
        while(!(num%prime[i])){
            dr[i]++;
            num /= prime[i];
        }
    }
    if(num==1)
        return 1;
    return 0;
}
void tran(int dr[][25],int w, int dp){
    int i=w+1;
    if(!dr[w][w]){
        while(i<dp){
            if(dr[w][i]){
                for(int j=w;j<20;j++){
                    dr[j][w] -= dr[j][i];
                }
                break;
            }
            i++;
        }
    }
    i=0;
    while(i<dp){
        if(i!=w && dr[w][w]){
            int k1 = dr[w][w];
            int k2 = dr[w][i];
            for(int j=w;j<20;j++){
                dr[j][i] = dr[j][i]*k1 - dr[j][w]*k2;
            }
        }
        i++;
    }
}

int solve(int dr[][25], int wn){
    int sum[25];
    for(int i=0;i<25;i++){
        sum[i]=0;
        for(int j=0;j<20;j++)
            if(dr[j][i]){
                sum[i]=1;
                break;
            }
    }
    int dp=0,j=0;
    while(j<25){
        if(sum[j]){
            for(int k=0;k<20;k++)
                dr[k][dp] = dr[k][j];
            j++;
            dp++;
        }
        else{
            j++;
        }
    }
    for(int i=0;i<wn;i++){
        tran(dr,i,dp);
    }
    int tmp=0;
    for(int i=0;i<dp;i++){
        if(dr[19][i])
            tmp=i+1;
    }
    if(tmp>wn)
        return 0;
    for(int i=0;i<wn;i++){
        if( !dr[i][i] ){
            if(dr[19][i])
                return 0;
        }
        if( dr[i][i] && dr[19][i]%dr[i][i] )
            return 0;
    }
    return 1;
}

int main(){
    int scenario;
    cin>>scenario;
    for(int i=1;i<=scenario;i++){
        cout<<"Scenario #"<<i<<":"<<endl;
        int wheel[20];
        int c=101;
        int wn;
        cin>>wn;
        for(int j=0;j<wn;j++){
            cin>>wheel[j];
            c = c>wheel[j]?wheel[j]:c;
        }
        for(int j=0;j<wn;j++){
            wheel[j] /= c;
        }
        int dr[20][25];
        for(int j=0;j<20;j++)
            for(int k=0;k<25;k++)
                dr[j][k]=0;
        int k=0;
        for(int j=0;j<wn;j++){
            if(wheel[j]>1){
                decom(wheel[j],dr[k]);
                k++;
            }
        }
        wn--;
        int tn;
        cin>>tn;
        while(tn--){
            int drt[20][25];
            for(int j=0;j<20;j++)
                for(int k=0;k<25;k++)
                    drt[j][k]=dr[j][k];
            int a,b;
            cin>>a>>b;
            cout<<"Gear ratio "<<a<<":"<<b;
            int tmp[25];
            for(int j=0;j<25;j++){
                tmp[j]=0;
                drt[19][j]=0;
            }
            decom(a,drt[19]);
            decom(b,tmp);
            for(int j=0;j<25;j++)
                drt[19][j] -= tmp[j];
            if(solve(drt,wn)){
                cout<<" can be realized"<<endl;
            }
            else{
                cout<<" cannot be realized."<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
