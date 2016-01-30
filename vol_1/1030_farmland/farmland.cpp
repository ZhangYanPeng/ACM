#include <iostream>
using namespace std;

struct rq{
    int queue[4];
    int sp;
};

struct node{
    struct rq data;
    struct node *next;
};

struct node* add(struct node* head, int data){
    if(head){


    }
    else{
        struct node* tmp = new struct node();

        return tmp;
    }
};

int main(){
    int m;
    cin>>m;
    while(m--){
        int n;
        cin>>n;
        int graph[200][200]={0};
        int cordinate[200][2];
        for(int i=0;i<n;i++){
            cin>>cordinate[i][0]>>cordinate[i][1];
            int t;
            cin>>t;
            while(t--){
                int temp;
                cin>>temp;
                graph[i][temp]=1;
            }
        }
        int aim;
        cin>>aim;

    }
    return 0;
}
