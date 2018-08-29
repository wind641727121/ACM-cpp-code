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
using namespace std;
#define bug(g) cout<<g<<endl
typedef long long ll;
int n,m,t;
const int maxn=500005;
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
    void insert(char *buf)
    {
        int len = strlen (buf);
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
    int query(char *buf)
    {
        build();
        int len=strlen(buf);
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
                    en[tmp]=0;
                }
                tmp=fail[tmp];
            }
        }
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
            char a[55];
            for(int i =0;i<n;i++)
            {cin>>a;ac.insert(a);}
            char s[1000005];
            cin>>s;
            cout<<ac.query(s)<<endl;
        }
    }
    return 0;
}
