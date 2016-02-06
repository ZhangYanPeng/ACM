#include <iostream>
using namespace std;
void sort(int* a, int* b,int* c){
	if(*a>*b){
		int t = *a;
		*a = *b;
		*b = t;
	}
	if(*b>*c){
		int t = *b;
		*b = *c;
		*c = t;
	}
	if(*a>*b){
		int t = *a;
		*a = *b;
		*b = t;
	}
	return;
}

int main(){
	int num=0;
	while(1){
		num++;
		int n;
		int square[90][2];
		int height[90][90];
		cin>>n;
		if(!n)
			break;
		for(int i=0;i<3*n;i++){
			for(int j=0;j<3*n;j++)
				height[i][j]=0;
		}
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			sort(&a,&b,&c);
			square[3*i][0]=a;
			square[3*i][1]=b;
			height[3*i][3*i]=c;
			square[3*i+1][0]=a;
			square[3*i+1][1]=c;
			height[3*i+1][3*i+1]=b;
			square[3*i+2][0]=b;
			square[3*i+2][1]=c;
			height[3*i+2][3*i+2]=a;
		}
		int check = 1;
		while(check){
			check=0;
			for(int i=0;i<3*n;i++){
				for(int j=0;j<3*n;j++){
					if(i==j)
						continue;
					if(square[i][0]>square[j][0] && square[i][1]>square[j][1]){
						for(int p=0;p<3*n;p++){
							if(height[p][i]){
								for(int q=0;q<3*n;q++){
									if(height[j][q]){
										if( (height[p][i]+height[j][q])>height[p][q] ){
											height[p][q] = height[p][i]+height[j][q];
											check++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		int maxH=0;
		for(int i=0;i<3*n;i++){
			for(int j=0;j<3*n;j++){
				maxH=height[i][j]>maxH?height[i][j]:maxH;			
			}
		}
		cout<<"Case "<<num<<": maximum height = "<<maxH<<endl;
	}
	return 0;
}