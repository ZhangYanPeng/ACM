#include <iostream>
using namespace std;
int tran(int* str,int n, int i){
    int len=0;
    if(i==2){
        while(n){
            str[len]=n&1;
            n=n>>1;
            len++;
        }
    }
    else if(i==4){
        while(n){
            str[len]=n&3;
            n=n>>2;
            len++;
        }
    }
    else if(i==8){
        while(n){
            str[len]=n&7;
            n=n>>3;
            len++;
        }
    }
    else if(i==16){
        while(n){
            str[len]=n&15;
            n=n>>4;
            len++;
        }
    }
    else{
        while(n){
            str[len]=n%i;
            n=n/i;
            len++;
        }
    }
    return len;
}
int main(){
    int n;
    while(1){
        cin>>n;
        if(!n)
            break;
        int s=1;
        cout<<"Number "<<n;
        for(int i=2;i<17;i++){
            int len;
            int str[17];
            len = tran(str,n,i);
            int check=1;
            int j=0;
            len--;
            while(j<len){
                if(str[j]!=str[len]){
                    check--;
                    break;
                }
                j++;
                len--;
            }
            if(check){
                if(s){
                    cout<<" is palindrom in basis";
                    s--;
                }
                cout<<" "<<i;
            }
        }
        if(s){
            cout<<" is not a palindrom";
        }
        cout<<endl;
    }
    return 0;
}
