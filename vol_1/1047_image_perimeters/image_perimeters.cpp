#include <iostream>
using namespace std;

int row,line,cr,cl;
char grid[20][20];

void tran(int r,int l){
    if(r<0||r>=row||l<0||l>=line)
        return;
    if(grid[r][l]=='X'){
        grid[r][l]='A';
        for(int i=r-1;i<=r+1;i++){
            for(int j=l-1;j<=l+1;j++){
                if(i<0||i>=row||j<0||j>=line)
                    continue;
                if(grid[i][j]=='X')
                    tran(i,j);
            }
        }
    }
    return;
}

int main(){
    while(1){
        cin>>row>>line>>cr>>cl;
        if(!row&&!line&&!cr&&!cl)
            break;
        for(int i=0;i<row;i++){
            for(int j=0;j<line;j++){
                char c=0;
                while(c!='X'&&c!='.'){
                    cin>>c;
                }
                grid[i][j]=c;
            }
        }
        tran(cr-1,cl-1);
        int perimeters=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<line;j++){
                if(grid[i][j]=='A'){
                    if( (i>0&&(grid[i-1][j]!='A') || !i) )
                        perimeters++;
                    if( (j>0&&(grid[i][j-1]!='A') || !j) )
                        perimeters++;
                    if( (i<(row-1)&&(grid[i+1][j]!='A') || i==(row-1)) )
                        perimeters++;
                    if( (j<(line-1)&&(grid[i][j+1]!='A') || j==(line-1)) )
                        perimeters++;
                }
            }
        }
        cout<<perimeters<<endl;
    }
    return 0;
}
