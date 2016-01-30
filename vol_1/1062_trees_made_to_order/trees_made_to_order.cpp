#include <iostream>
#include <string>
using namespace std;
long cont[19];
long n;

string decop(int num, int n){
    if(!num)
        return "";
    if(num==1)
        return "X";
    int numl=0,numr=num-1;
    while(n>cont[numl]*cont[numr]){
        n-=cont[numl]*cont[numr];
        numl++;
        numr--;
    }
    string strl = decop(numl,(n-1)/cont[numr]+1);
    if(strl.length())
        strl = "(" + strl +")";
    string strr = decop(numr,(n-1)%cont[numr]+1);
    if(strr.length())
        strr = "(" + strr +")";
    string str = strl + "X" + strr;
    return str;
}

int main(){
    cont[1]=cont[0]=1;
    for(int i=2;i<19;i++){
        int tmp=0;
        for(int k=0;k<i;k++){
            tmp += cont[k]*cont[i-1-k];
        }
        cont[i]=tmp;
    }

    while(1){
        cin>>n;
        if(!n)
            break;
        int num=0;
        while((n+1)>cont[num]){
            n-=cont[num];
            num++;
        }
        string tree = decop(num,n+1);
        cout<<tree<<endl;
    }
    return 0;
}
