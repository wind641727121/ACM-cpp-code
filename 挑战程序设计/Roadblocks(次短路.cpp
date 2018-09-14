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
typedef long long ll;
#define bug1(g) cout<<"test: "<<g<<endl
#define bug2(g,i) cout<<"test: "<<g<<" "<<i<<endl
#define bug3(g,i,k) cout<<"test: "<<g<<" "<<i<<" "<<k<<endl
struct edge{
    int next,to;
    ll w;
}a[200005];
int head[5005],cnt;
inline void addedge(int u,int v,ll w)
{
    a[++cnt].next=head[u];
    a[cnt].w=w;
    a[cnt].to=v;
    head[u]=cnt;
}
struct node//(int a,int b)
{
    int p,w;
    node(int x=0,int y=0){p=x;w=y;}
    friend bool operator <(node a,node b){return a.w>b.w;}
};

ll dis1[5005],dis2[5005];

int n,m,t;
priority_queue<node> q;
int dij()
{
    for(int i=0;i<=n;i++)dis1[i]=dis2[i]=1e9;
    dis1[1]=0;
    q.push(node(1,0));
    while(!q.empty())
    {
        int u =q.top().p;ll d=q.top().w;q.pop();
      //  bug2(u,d);
        if(d>dis2[u]) continue;
        //是不是第二短路
       // if(d==dis2[u]) bug2(u,d);
        for(int i =head[u];i;i=a[i].next)
        {
           ll dis=d+a[i].w,v=a[i].to;
            if(dis<dis1[v])
            {
                swap(dis1[v],dis);
                q.push(node(v,dis1[v]));
            }
            if(dis<dis2[v]&&dis>dis1[v])
            {
                dis2[v]=dis;
                q.push(node(v,dis2[v]));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m)
    {
        memset(head,0,sizeof head);
        cnt=0;
        for(int i =0;i<m;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            addedge(x,y,z);
            addedge(y,x,z);
        }
         dij();
         cout<<dis2[n]<<endl;
    }
    return 0;
}
