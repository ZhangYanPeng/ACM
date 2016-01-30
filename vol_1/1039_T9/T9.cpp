#include  <iostream>
#include  <string>
using namespace std;
int t9(char c){
	switch(c){
		case 'a':
		case 'b':
		case 'c':return 2;break;
		case 'd':
		case 'e':
		case 'f':return 3;break;
		case 'g':
		case 'h':
		case 'i':return 4;break;
		case 'j':
		case 'k':
		case 'l':return 5;break;
		case 'm':
		case 'n':
		case 'o':return 6;break;
		case 'p':
		case 'q':
		case 'r':
		case 's':return 7;break;
		case 't':
		case 'u':
		case 'v':return 8;break;
		case 'w':
		case 'x':
		case 'y':
		case 'z':return 9;break;
	}
	return 0;
}
struct node{
	int num;
	char letter;
	string str;
	int frq;
	struct node* next;
	struct node* other;
};
void rel(struct node* pt){
    if(pt!=NULL){
        if(pt->next!=NULL)
            rel(pt->next);
        if(pt->other!=NULL)
            rel(pt->other);
        delete pt;
    }
}
void pr(struct node* pt){
    if(pt!=NULL){
        if(pt->next)
            pr(pt->next);
        if(pt->other)
            pr(pt->other);
        cout<<pt->str<<"*"<<endl;
    }
}

void  tran(string str,struct node* cdic,struct node* dic){
    struct node* pt = dic->next;
    while(pt){
        string tstr = str + " ";
        tstr[tstr.length()-1]=pt->letter;
        int nm = t9(pt->letter);
        int fq = pt->frq;
        struct node* ptc = cdic->next;
        if(!ptc){
            ptc = new struct node;
            ptc->num=nm;
            ptc->frq=fq;
            ptc->str=tstr;
            ptc->other=NULL;
            ptc->next=NULL;
            cdic->next = ptc;
        }
        else{
            while(ptc->other&&ptc->num!=nm)
                ptc=ptc->other;
            if(ptc->num==nm){
                if(ptc->frq<fq){
                    ptc->frq = fq;
                    ptc->str = tstr;
                }
            }
            else{
                struct node* tmp = new struct node;
                tmp->num=nm;
                tmp->frq=fq;
                tmp->str=tstr;
                tmp->next=NULL;
                tmp->other=NULL;
                ptc->other = tmp;
                ptc=tmp;
            }
        }
        tran(tstr,ptc,pt);
        pt=pt->other;
    }

};

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"Scenario #"<<i<<":"<<endl;
		int dsize;
		cin>>dsize;
		struct node* dic = new struct node;
		dic->frq=0;
		dic->letter=0;
		dic->other=NULL;
		dic->next=NULL;
		for(int j=0;j<dsize;j++){
			string str;
			int fq;
			cin>>str>>fq;
            struct node* pf=dic;
            struct node* pt=dic->next;
			int k=0;
			while(str[k]){
				if(!pt){
					struct node* tmp = new struct node;
					tmp->letter=str[k];
					tmp->frq=fq;
					tmp->next=NULL;
					tmp->other=NULL;
					pf->next=tmp;
					pf=tmp;
					pt=pf->next;
				}
				else{
					while( pt->other && pt->letter != str[k] )
						pt=pt->other;
					if( pt->letter == str[k] ){
						pt->frq+=fq;
						pf=pt;
						pt=pf->next;
					}
					else{
						struct node* tmp = new struct node;
						tmp->letter=str[k];
                        tmp->frq=fq;
						tmp->next=NULL;
						tmp->other=NULL;
						pt->other=tmp;
						pf=tmp;
						pt=pf->next;
					}
				}
				k++;
			}
		}

        struct node* cdic = new struct node;
        cdic->num=-1;
        cdic->letter=0;
        cdic->next=NULL;
        cdic->other=NULL;
        tran("",cdic,dic);
        int testn;
        cin>>testn;
        string tststr;
        while(testn--){
            cin>>tststr;
            int k=0;
            struct node* pt = cdic;
            while(tststr[k]!='1'){
                if(pt==NULL){
                    cout<<"MANUALLY"<<endl;
                    k++;
                    continue;
                }
                pt=pt->next;
                int aim = tststr[k]-'0';
                if(pt==NULL){
                    cout<<"MANUALLY"<<endl;
                    pt=NULL;
                    k++;
                    continue;
                }
                while(pt->other&&pt->num!=aim)
                    pt=pt->other;
                if(pt->num==aim)
                    cout<<pt->str<<endl;
                else{
                    cout<<"MANUALLY"<<endl;
                    pt=NULL;
                }
                k++;
            }
            cout<<endl;
        }
        rel(dic);
        rel(cdic);
        cout<<endl;
	}
	return 0;
}
