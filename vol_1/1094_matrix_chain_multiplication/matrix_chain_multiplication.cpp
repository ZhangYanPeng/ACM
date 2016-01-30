#include <iostream>
using namespace std;

int main(){
    int n;
    char matrices[26];
    int mtrsize[26][2];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>matrices[i];
        cin>>mtrsize[i][0]>>mtrsize[i][1];
    }
    string exp;
    while(cin>>exp){
        int stacksize[1000][2];
        int top=0;
        int cp=0;
        int multimes=0;
        int check=1;
        while(exp[cp]){
            if(exp[cp]>='A'&&exp[cp]<='Z'){
                int j=0;
                while(matrices[j]!=exp[cp])
                    j++;
                stacksize[top][0]=mtrsize[j][0];
                stacksize[top][1]=mtrsize[j][1];
                top++;
                cp++;
            }
            else if(exp[cp]==')'){
                top--;
                if(stacksize[top-1][1]!=stacksize[top][0]){
                    check=0;
                    break;
                }
                multimes += stacksize[top-1][0]*stacksize[top][0]*stacksize[top][1];
                stacksize[top-1][1]=stacksize[top][1];
                cp++;
            }
            else
                cp++;
        }
        if(check)
            cout<<multimes<<endl;
        else
            cout<<"error"<<endl;
    }
    return 0;
}
