#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;
#define N 50
string string1;
int  PPlus[N];
int mul[N];
int  pow[N];
string produce_str(string &p,int t);
string tostring(int x);
int main()
{
    int cnt=0;
    while(cin>>string1)
    {
        cnt++;
        if(string1[0]=='*')  break;
        int tmp=string1.find("=");
        string tmp_string=string1.substr(tmp+1);
        string  k,res,res1;
        if(cnt!=1) cout<<endl;
         cout<<"Expression "<<string1.substr(0,tmp-1)<<":"<<endl;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            getline(cin,k);
            while(k=="") getline(cin,k);
            istringstream in(k);
            string str=tmp_string;
            res=string1.substr(0,tmp-1);
            int tt;
             while(in>>tt)
            {
                res1.assign("op(");
                string t2=tostring(tt);
                res1+=t2;
                res1.push_back(',');
                res =res1+res; res.push_back(')');
                str=produce_str(str,tt);
            }
            cout<<res<<'=';
            cout<<str<<endl;
        }

    }
}

string produce_str(string &p,int t)
{
    int len=p.length(); int t1,cnt1,cnt2,cnt3;
    cnt1=cnt2=cnt3=0;
    t1=0;
    PPlus[0]=mul[0]=pow[0]=-1;
    for(int i=0;i<len;i++)
    {
        switch(p[i])
        {
            case '+': case '-':if(!t1) PPlus[++cnt1 ]=i; break;
            case '*': if(!t1) mul[++cnt2]=i; break;
            case '^': if(!t1) pow[++cnt3]=i;break;
            case '(' : t1++;break;
            case ')' :t1--; break;
        }
    }
    if(cnt1!=0) {PPlus[++cnt1]=len; return p.substr(PPlus[t-1]+1,PPlus[t]-PPlus[t-1]-1);}
    if(cnt2!=0) {mul[++cnt2]=len;return p.substr(mul[t-1]+1,mul[t]-mul[t-1]-1);}
    if(cnt3!=0) {pow[++cnt3]=len;return p.substr(pow[t-1]+1,pow[t]-pow[t-1]-1);}
    if(p[0]!='(') return p;
    return p.substr(1,len-2);
}

string tostring(int x)
{
    char p[10];
    sprintf(p,"%d",x);
    string t;
    t.assign(p);
    return t;
}
