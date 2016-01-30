#include <iostream>
using namespace std;
long humble[5842];
int sum;
void find_hum(long cur,int pri){
    long curn;
    switch(pri){
    case 2:
        {
            curn = cur*2;
            if(cur<=2000000000/2){
                humble[sum]=curn;
                sum++;
                find_hum(curn,2);
            }
        }
    case 3:
        {
            curn = cur*3;
            if(cur<=2000000000/3){
                humble[sum]=curn;
                sum++;
                find_hum(curn,3);
            }
        }
    case 5:
        {
            curn = cur*5;
            if(cur<=2000000000/5){
                humble[sum]=curn;
                sum++;
                find_hum(curn,5);
            }
        }
    case 7:
        {
            curn = cur*7;
            if(cur<=2000000000/7){
                humble[sum]=curn;
                sum++;
                find_hum(curn,7);
            }
            break;
        }
    }
    return;
}
int main(){
    sum=1;
    humble[0]=1;
    long cur=1;
    find_hum(cur,2);
    for(int i=0;i<5842;i++){
        int check = 0;
        for(int j=0;j<5841-i;j++){
            if(humble[j]>humble[j+1]){
                long tmp = humble[j];
                humble[j] = humble[j+1];
                humble[j+1] = tmp;
                check++;
            }
        }
        if(!check)
            break;
    }
    while(1){
        int num;
        cin>>num;
        if(!num)
            break;
        cout<<"The "<<num;
        if(num%10==1&&num%100!=11)
            cout<<"st";
        else if(num%10==2&&num%100!=12)
            cout<<"nd";
        else if(num%10==3&&num%100!=13)
            cout<<"rd";
        else
            cout<<"th";
        cout<<" humble number is "<<humble[num-1]<<"."<<endl;
    }
    return 0;
}
