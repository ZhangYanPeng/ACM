#include <iostream>
using namespace std;

int main(){
	int ca[2][501][501];
	int num=0;
	while(1){
		int cn;
		cin>>cn;
		if(!cn)
			break;
		int inf[3][3];
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				cin>>inf[i][j];
		int sq[4];
		for(int i=0;i<4;i++)
			cin>>sq[i];
		for(int i=0;i<2;i++)
			for(int j=0;j<501;j++)
				for(int k=0;k<501;k++)
					ca[i][j][k]=-1;
		ca[0][0][0]=0;
		for(int i=1;i<=cn;i++){
			int wt,st;
			cin>>wt>>st;
			for(int p=0;p<=500;p++){
				if( p*inf[0][0]>wt || p*inf[0][1]>st )
					break;
				for(int q=0;q<=500;q++){
					if( (p*inf[0][0]+q*inf[1][0])>wt || (p*inf[0][1]+q*inf[1][1])>st )
                        break;
                    else{
                        int rt = (wt-p*inf[0][0]-q*inf[1][0])/inf[2][0];
                        int r = (st-p*inf[0][1]-q*inf[1][1])/inf[2][1];
                        r = r>rt?rt:r;
                        int ct,ft;
                        ct = i%2;
                        ft = (ct+1)%2;
                        for(int j=0;j<501;j++){
                            if(ca[ft][j][0]<0)
                                break;
                            for(int k=0;k<501;k++){
                                if(ca[ft][j][k]<0)
                                    break;
                                else if( ca[ft][j][k]+r > ca[ct][j+p][k+q] ){
                                    ca[ct][j+p][k+q]=ca[ft][j][k]+r;
                                }
                            }
                        }
                    }
				}
			}
		}
		cn = cn%2;
		int dc=0;
		for(int i=0;i<501;i++){
			if(ca[cn][i][0]<0)
				break;
			for(int j=0;j<501;j++){
				if(ca[cn][i][j]<0)
					break;
				else{
					int sqn = i/sq[0];
					sqn = (j/sq[1]>sqn)?sqn:j/sq[1];
					sqn = (ca[cn][i][j]/sq[2]>sqn)?sqn:ca[cn][i][j]/sq[2];
					int tdc = sqn*(sq[3]-sq[0]*inf[0][2]-sq[1]*inf[1][2]-sq[2]*inf[2][2]);
					tdc += inf[0][2]*i;
					tdc += inf[1][2]*j;
					tdc += inf[2][2]*ca[cn][i][j];
					dc = dc>tdc?dc:tdc;
				}
			}
		}
		if(num)
			cout<<endl;
		cout<<"Case " <<num+1<<": "<<dc<<endl;
		num++;
	}
	return 0;
}
