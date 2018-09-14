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
#define bug1(g) cout<<"test: "<<g<<endl
#define bug2(g,i) cout<<"test: "<<g<<" "<<i<<endl
#define bug3(g,i,k) cout<<"test: "<<g<<" "<<i<<" "<<k<<endl
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

typedef long long ll;
int n,m,d;
int cnt=0,head[1005];
struct edge
{
    int next,to,w;
}a[30005];
void addedge(int u,int v,int w)
{
    a[++cnt].next=head[u];
    a[cnt].to=v;
    a[cnt].w=w;
    head[u]=cnt;
}
int dis[1005];
int r[1005];
bool vis[1005];
queue<int> q;
int spfa()
{
    for(int i =0;i<=n;i++) dis[i]=0x3f3f3f,vis[i]=r[i]=0;
    dis[1]=0;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int p =q.front();q.pop();
        vis[p]=0;
        if(++r[p]>n)return 0;
        for(int i =head[p];i;i=a[i].next)
        {
            int d = dis[p]+a[i].w,v=a[i].to;
            if(dis[v]>d)
            {
                if(vis[v]==0)q.push(v),vis[v]=1;
                dis[v]=d;
            }
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m>>d)
    {
        int x,y,z;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            addedge(x,y,z);
        }
        for(int i =0;i<d;i++)
        {
            cin>>x>>y>>z;
            addedge(y,x,-z);
        }
        for(int i =1;i<=n;i++)
        {
            addedge(i,i-1,0);
        }
        if(spfa()==0) cout<<-1<<endl;
        else{
            if(dis[n]==0x3f3f3f)cout<<-2<<endl;
            else cout<<dis[n]<<endl;
        }
        while(!q.empty())q.pop();
    }
    return 0;
}
