#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
//#include<pair>
using namespace std;
#define bug(g) cout<<g<<endl
typedef long long ll;
int n,m,t;
const int maxn=500005;
vector<string> a;
struct tri
{
    int next[maxn][26],fail[maxn],en[maxn];
    int root,cnt;
    int new_node()
    {
        memset(next[cnt],-1,sizeof next[cnt]);
        en[cnt++]=0;
        return cnt-1;
    }
    void init()
    {
        cnt = 0;
        root=new_node();
    }
    void insert(string buf)
    {
        int len = buf.size();
        int now = root;
        for(int i =0;i<len;i++)
        {
            int id = buf[i]-'a';
            if(next[now][id]==-1)
                next[now][id]=new_node();
            now = next[now][id];
        }
        ++en[now];
    }
    void build()
    {
        queue<int>q;
        fail[root]=root;
        for(int i =0;i<26;i++)
        {
            if(next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty())
        {
            int now = q.front();q.pop();
            for(int i = 0;i<26;i++)
            {
                if(next[now][i]==-1) next[now][i]=next[fail[now]][i];
                else {fail[next[now][i]]=next[fail[now]][i];
                        q.push(next[now][i]);
            }
        }
    }
    }
    int query(string buf)
    {
        vector<pair<int,int> >ha;
        int len=buf.size();
        int now = root;
        int res=0;
        for(int i =0;i<len;i++)
        {
            int id = buf[i]-'a';
            now = next[now][id];
            int tmp=now;
            while(tmp!=root)
            {
                if(en[tmp])
                {
                    res+=en[tmp];

                  ha.push_back(make_pair(tmp,en[tmp]));
                  en[tmp]=0;
                }
                tmp=fail[tmp];
            }
        }
        for(int i =0;i<ha.size();++i)
            en[ha[i].first]=ha[i].second;
        return res;
    }
}ac;
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            ac.init();
            string s;
            a.clear();
            int maxx=0;
            vector<int>maxi;
            for(int i =0;i<n;i++)
            {
                cin>>s;a.push_back(s);ac.insert(s);
                if(s.size()>maxx)
                {
                    maxx=s.size();maxi.clear();maxi.push_back(i);
                }
                else if(s.size()==maxx) maxi.push_back(i);
            }

            // a.erase(unique(a.begin(),a.end()),a.end());
              //for(int i =0;i<a.size();i++) ac.insert(a[i]);
              ac.build();
             int flag=1;
             //cout<<a.size();
             for(int i =0;i<maxi.size()&&flag;i++)
             {

                if(ac.query(a[maxi[i]])>=a.size()) {flag=0;cout<<a[maxi[i]]<<endl;break;}
             }
             if(flag) cout<<"No"<<endl;
        }
    }
    return 0;
}
