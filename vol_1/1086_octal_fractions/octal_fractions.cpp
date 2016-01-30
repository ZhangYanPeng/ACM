#include <iostream>
#include <string>
using namespace std;
int multi(string* octal){
    string ts = *octal;
    ts = "00"+ts;
    for(int i=0;i<ts.size();i++){
        ts[i] = (ts[i]-'0')*10;
    }
    for(int i=ts.size()-1;i>0;i--){
        ts[i-1]+=ts[i]/8;
        ts[i]=ts[i]%8+'0';
    }
    *octal = ts.substr(2,ts.size()-1);
    return ts[0]*8+ts[1]-'0';
}

int main(){
    string octal;
    while(cin>>octal){
        cout<<octal<<" [8] = ";
        int i=0;
        while(octal[i]=='0'||octal[i]=='.')
            i++;
        if(octal[0]=='1'||i>=octal.size()){
            cout<<octal[0];
        }
        else{
            cout<<"0.";
            octal = octal.substr(2,octal.size()-1);
            while(true){
                i=0;
                while(octal[i]=='0')
                    i++;
                if(i>=octal.size())
                    break;
                cout<<multi(&octal);
            }
        }
        cout<<" [10]"<<endl;
    }
    return 0;
}
