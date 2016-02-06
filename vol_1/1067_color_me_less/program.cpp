#include <iostream>
using namespace std;

int main(){
	int color[16][4];
	for(int i=0;i<16;i++){
		cin>>color[i][0]>>color[i][1]>>color[i][2];
		color[i][3]=color[i][0]*color[i][0]+color[i][1]*color[i][1]+color[i][2]*color[i][2];
	}
	int rgb[5];
	while(1){
		cin>>rgb[0]>>rgb[1]>>rgb[2];
		rgb[3]=255*255*3+1;
		if(rgb[0]<0)
			break;
		for(int i=0;i<16;i++){
			int tmp = color[i][3]-2*rgb[0]*color[i][0]-2*rgb[1]*color[i][1]-2*rgb[2]*color[i][2];
			if(tmp<rgb[3]){
				rgb[3]=tmp;
				rgb[4]=i;
			}
		}
		cout<<"("<<rgb[0]<<","<<rgb[1]<<","<<rgb[2]<<")"<<" maps to ("<<color[rgb[4]][0]<<","<<color[rgb[4]][1]<<","<<color[rgb[4]][2]<<")"<<endl;
	}
	return 0;
}