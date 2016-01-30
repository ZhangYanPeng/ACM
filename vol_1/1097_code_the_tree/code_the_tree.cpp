#include <iostream>
using namespace std;

struct node{
	struct node *parent,*son,*brother;
	int num;
	int state;
};

int maxv;
struct node* maxn;
int tran[50];

struct node* img_in(struct node* pp){
	char c;
	int n;
	cin>>n;
	struct node* pn = new struct node;
	pn->num = n;
	pn->state = 1;
	pn->parent = pp;
	pn->son = NULL;
	pn->brother = NULL;
	if(maxv<n){
        maxv = n;
        maxn = pn;
	}
	struct node* pt = pn;
	while(1){
		cin>>c;
		if(c=='('){
			if(pt == pn){
				pt->son = img_in(pn);
				pt = pt->son;
			}
			else{
				pt->brother = img_in(pn);
				pt = pt->brother;
			}
		}
		else
			break;
	}
	return pn;
}

int mergec(int* c1, int *c2,int l1, int l2){
    int p1=l1-1,p2=l2-1;
    for(int i=l1+l2-1;i>0;i--){
        if( p1>0 && (p2<0||c1[p1]<c2[p2]) ){
            c1[i]=c1[p1];
            p1--;
        }
        else{
            c1[i]=c2[p2];
            p2--;
        }
    }
    return l1+l2;
}

int codetree(struct node* p,int *code,int pos){
    int ct1[50],ct2[50];
    int l1=0,l2=0;
    int tr=0;
    if(p->state){
        p->state=0;
        ct1[0]=p->num;
        l1++;
        if(p->parent && p->parent->state==0){
            tr=p->parent->num;
        }
        else{
            struct node* tmp = p->son;
            while(tmp){
                if(tmp->state==0){
                    tr=tmp->num;
                    break;
                }
                tmp=tmp->brother;
            }
        }
        if(tr){
            tran[p->num]=tr;
        }
    }
    else{
        return 0;
    }
    if(p->parent&&p->parent->state){
        l2 = codetree(p->parent,ct2,0);
        l1 = mergec(ct1,ct2,l1,l2);
    }
    struct node* pt = p;
    pt = p->son;
    while(pt){
        if(pt->state){
            l2 = codetree(pt,ct2,0);
            l1 = mergec(ct1,ct2,l1,l2);
        }
        pt = pt->brother;
    }
    for(int i=0;i<l1;i++){
        code[i]=ct1[i];
    }
    return l1;
}

void pr(struct node* p){
	if(p){
        cout<<p->num;
		if(p->son)
			pr(p->son);
		if(p->brother)
			pr(p->brother);
	}
}

void del(struct node* p){
	if(p){
		if(p->son)
			del(p->son);
		if(p->brother)
			del(p->brother);
        delete(p);
	}
}

int main(){
	struct node* root;
	char c;
	while(cin>>c){
            maxv=0;
		if(c != '(')
			continue;
		root = NULL;
		root = img_in(root);
		int code[50];
		int l = codetree(maxn,code,0);
        for(int i=l-1;i>0;i--){
            cout<<tran[code[i]];
            if(i!=1)
                cout<<" ";
        }
        cout<<endl;
		del(root);
	}
	return 0;
}
