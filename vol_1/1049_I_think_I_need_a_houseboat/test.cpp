#include<iostream>
 #define N 10004
 #include<cstdio>
 #include<algorithm>
 using namespace std;
 int deadline;
 int n_cpu,n_memory,n_job;
 struct JOB
 {
     int cpu,mem,st,ed,value,bonus,punish;
 };
 struct LINK
 {
     int id;
     LINK *next;
 };
 JOB job[N];
 LINK  head;
 LINK *tail; int total;
 int cmp(const void *p,const void *q);
 int cc=0;
 int main()
 {
     while(cin>>deadline&&deadline)
     {
         cc++;
         total=0;
         head.next=NULL;
         tail=&head;
         cin>>n_cpu>>n_memory>>n_job;
         for(int i=0;i<n_job;i++)
         {
             scanf("%d%d%d%d%d%d%d",&job[i].cpu,&job[i].mem,&job[i].st,&job[i].ed,&job[i].value,&job[i].bonus,&job[i].punish);
         }
         qsort(job,n_job,sizeof(job[0]),cmp);
         int cnt=0;
         for(int i=1;i<deadline;i++)
         {
             while(cnt<n_job&&job[cnt].st==i)
                {
                 LINK *tmp=new LINK;
                tmp->id=cnt; tmp->next=NULL;
                tail->next=tmp;
                 tail=tmp;
                 cnt++;
             }
             if(head.next!=NULL)
             {
               LINK *pre=&head;
               LINK  *cur=head.next;
               int c=n_cpu; int m=n_memory;
               while(cur!=NULL) {
                   int tt=cur->id;
                   if(c>=job[tt].cpu&&m>=job[tt].mem)
                   {
                       c-=job[tt].cpu; m-=job[tt].mem;
                       total+=job[tt].value;
                       int tmp=job[tt].ed-i-1;
                       if(tmp<0) total+=tmp*job[tt].punish;
                       else total+=tmp*job[tt].bonus;
                       LINK *k=cur;
                       cur=cur->next;
                       pre->next=cur;
                       delete k;
                   }
                   else {cur=cur->next; pre=pre->next;}
               }
               tail=pre;
               }
         }
         if(head.next!=NULL)
         {
             LINK *cur=head.next;
             while(cur!=NULL)
             {
                 int tt=cur->id;
                 if(job[tt].ed<deadline) {total-=(deadline-job[tt].ed)*job[tt].punish;}
                 cur=cur->next;
             }
         }
         cout<<"Case "<<cc<<": ";
         cout<<total<<endl<<endl;
     }

}



int cmp(const void *p,const void *q)
 {
     JOB *m=(JOB *)p;
     JOB *n=(JOB *)q;
     if(m->st==n->st)
     return n->value-m->value;
     return  m->st-n->st;
 }
