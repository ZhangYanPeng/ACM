#include <stdio.h>
#include <string.h>

int main(){
    char rotor[30],cryp[1000];
    int i,j,blank=0,num=1,m,n,temp[26],tran[3][26];
    while(scanf("%d", &m)>=0&&m){
        if(blank)
            printf("\n");
        else
            blank=1;
        printf("Enigma %d:\n",num++);
        for(i=0;i<3;i++){
            scanf("%s",rotor);
            for(j=0;j<m;j++){
                temp[j] = (int)(rotor[j]-'A')-j;
                tran[i][(j+temp[j])%m]=temp[j];
            }
        }
        scanf("%d", &n);
        int lp0,lp1,lp2,t,len;
        for(i=0;i<n;i++){
            lp0=lp1=lp2=0;
            scanf("%s",cryp);
            len=strlen(cryp);
            for(j = 0; j < len; j++){
                t = cryp[j] - 'A';
                t -= tran[2][(t + lp2) % m];
                t = (t + m) % m;
                t -= tran[1][(t + lp1) % m];
                t = (t + m) % m;
                t -= tran[0][(t + lp0) % m];
                t = (t + m) % m;
                printf("%c", t+'a');
                lp0 = (lp0 + m - 1) % m;
                if((j+1) % m == 0)
                    lp1 = (lp1 + m - 1) % m;
                if((j+1) % (m*m) == 0)
                    lp2 = (lp2 + m - 1) % m;
            }
            printf("\n");
        }
    }
    return 0;
}
