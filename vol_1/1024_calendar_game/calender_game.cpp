#include <iostream>
using namespace std;
int date_status[102][12][31];
int mark[102][12][31];
void nextday(int *y,int* m,int* d){
    if((*d)==30){
        (*d)=0;
        (*m)++;
        if((*m)==12){
            (*m)=0;
            (*y)++;
        }
        return;
    }
    if((*d)==29 && ((*m)==3||(*m)==5||(*m)==8||(*m)==10) ){
        (*d)=0;
        (*m)++;
        return;
    }
    if((*m)==1 && (*d)==28){
        (*d)=0;
        (*m)++;
        return;
    }
    if((*m)==1 && (*d)==27 && ((*y)%4 || !(*y)) ){
        (*d)=0;
        (*m)++;
        return;
    }
    (*d)++;
    return;
}
int nextmonth(int *y,int* m,int* d){
    if((*d)==30 && ((*m)==0||(*m)==2||(*m)==4||(*m)==6||(*m)==7||(*m)==9))
        return 0;
    if((*d)==29 && (*m)==0)
        return 0;
    if( (*d)==28 && (*m)==0 && ( ((*y)%4) || !(*y) ) )
       return 0;
    if((*m)==11){
        (*m)=0;
        (*y)++;
    }
    else (*m)++;
    return 1;
}
int check(int y, int m, int d){
    int ty,tm,td;
    ty=y;
    tm=m;
    td=d;
    nextday(&ty,&tm,&td);
    if(date_status[ty][tm][td])
        return 0;
    ty=y;
    tm=m;
    td=d;
    if(nextmonth(&ty,&tm,&td)){
        if(date_status[ty][tm][td])
            return 0;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<102;i++)
        for(int j=0;j<12;j++)
            for(int k=0;k<31;k++){
                mark[i][j][k]=0;
                date_status[i][j][k]=1;
            }
    for(int i=0;i<31;i++){
        date_status[101][11][i]=0;
    }
    for(int i=4;i<31;i++){
        date_status[101][10][i]=0;
    }
    for(int i=0;i<102;i++){
        date_status[i][1][30]=0;
        date_status[i][1][29]=0;
        date_status[i][3][30]=0;
        date_status[i][5][30]=0;
        date_status[i][8][30]=0;
        date_status[i][10][30]=0;
        if( i%4 ){
            date_status[i][1][28]=0;
        }
    }
    date_status[0][1][28]=0;
    while(n--){
        int y,m,d;
        cin>>y>>m>>d;
        y=y-1900;
        m--;
        d--;
        int yd=101,md,dd;
        while(yd>=0){
            md=11;
            while(md>=0){
                dd=30;
                while(dd>=0){
                    if(!mark[yd][md][dd]){
                        if(date_status[yd][md][dd]){
                            date_status[yd][md][dd]=check(yd,md,dd);
                        }
                        mark[yd][md][dd]=1;
                        if(yd==y&&md==m&&dd==d){
                            break;
                        }
                    }
                    dd--;
                }
                if(yd==y&&md==m&&dd==d){
                    break;
                }
                md--;
            }
            if(yd==y&&md==m&&dd==d){
                break;
            }
            yd--;
        }
        if(!date_status[y][m][d])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
