#include <iostream>
using namespace std;
int main(){
    int board[50][50];
    int num=0;
    while(1){
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                board[i][j]=0;
        for(int i=10;i<30;i++)
            board[24][i]=i-9;
        int n;
        int hx,hy,tx,ty;
        hy=24;
        hx=29;
        cin>>n;
        if(!n)
            break;
        if(num)
            cout<<endl;
        num++;
        int i=1;
        int check=1;
        while(i<=n){
            char c=0;
            while(c<'A'||c>'Z')
                cin>>c;
            if(check){
                int ax,ay;
                switch(c){
                case 'N':ay=hy-1;ax=hx;break;
                case 'S':ay=hy+1;ax=hx;break;
                case 'E':ay=hy;ax=hx+1;break;
                case 'W':ay=hy;ax=hx-1;break;
                }
                if(ay>=50||ax>=50||ay<0||ax<0){
                    cout<<"The worm ran off the board on move "<<i<<".";
                    check=0;
                }
                if(board[ay][ax] && board[ay][ax]>i){
                    cout<<"The worm ran into itself on move "<<i<<".";
                    check=0;
                }
                board[ay][ax]=i+20;
                hx=ax;
                hy=ay;
            }
            i++;
        }
        if(check)
            cout<<"The worm successfully made all "<<n<<" moves.";
    }
    return 0;
}
