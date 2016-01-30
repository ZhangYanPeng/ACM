#include <iostream>
#include <string.h>
using namespace std;
int moves[64][64];

void cal(){
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++)
            moves[i][j]=-1;
        moves[i][i]=0;
    }
    for(int i=0;i<56;i++){
        int j=i+6;
        if((i%8)>=2&&j<64){
            moves[i][j]=1;
            moves[j][i]=1;
        }
        j=i+10;
        if((i%8)<=5&&j<64){
            moves[i][j]=1;
            moves[j][i]=1;
        }
        j=i+15;
        if((i%8)>=1&&j<64){
            moves[i][j]=1;
            moves[j][i]=1;
        }
        j=i+17;
        if((i%8)<=6&&j<64){
            moves[i][j]=1;
            moves[j][i]=1;
        }
    }
    int check=1;
    while(check){
        check=0;
        for(int i=0;i<64;i++){
            for(int j=i+1;j<64;j++){
                for(int k=0;k<64;k++){
                    if(moves[i][k]>0&&moves[k][j]>0){
                        if(moves[i][j]<0){
                            moves[i][j]=moves[i][k]+moves[k][j];
                            moves[j][i]=moves[i][j];
                            check++;
                        }
                        else if((moves[i][k]+moves[k][j])<moves[i][j]){
                            moves[i][j]=moves[i][k]+moves[k][j];
                            moves[j][i]=moves[i][j];
                            check++;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cal();
    string st,ed;
    while(cin>>st>>ed){
        int stn,edn;
        stn = (st[0]-'a')*8+st[1]-'1';
        edn = (ed[0]-'a')*8+ed[1]-'1';
        cout<<"To get from "<<st<<" to "<<ed<<" takes "<<moves[stn][edn]<<" knight moves."<<endl;
    }
}
