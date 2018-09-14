#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define maxm 200005
struct edge{
 int next,to,w;
}a[maxm];
int cnt=0,head[maxn];
inline int read()
{
    int w=0,s=1;
    char c;
    c=getchar();
    while(c<'0'||c>'9'){if(c=='-')s=-1;if(c==-1)exit(0);c=getchar();}
    while(c<='9'&&c>='0'){w=w*10+c-'0';c=getchar();}
    return w*s;
}
inline void addedge(int u,int v,int w)
{
    a[++cnt].next=head[u];
    a[cnt].to=v;
    a[cnt].w=w;
    head[u]=cnt ;
}
bool vis[maxn];
int dis[maxn];
struct node {
int p,d;
node(int x=0,int y=0){p=x,d=y;}
friend bool operator <(node a,node b){return a.d>b.d;}
};
priority_queue<node>q;
int n,m,s;
void dij()
{

    dis[s]=0;
    q.push(node(s,0));
    while(!q.empty())
    {
        int u = q.top().p,w=q.top().d;
        q.pop();
        vis[u]=1;
        if(dis[u]!=w)continue;
        for(int i =head[u];i;i=a[i].next)
        {
            int v =a[i].to;
            if(vis[v])continue;
            if(dis[v]>a[i].w+dis[u])
            {
                dis[v]=a[i].w+dis[u];
                q.push(node(v,dis[v]));
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(0);
    n=read();m=read();s=read();
   // cin>>n>>m>>s;
    memset(dis,0x3f,sizeof dis);
    int a,b,c;
    for(int i =0;i<m;i++)
    {
         a=read(),b=read(),c=read();
        addedge(a,b,c);
    }
    dij();
    for(int i =1;i<=n;i++)
    {printf("%d",dis[i]);
        if(i!=n)printf(" ");
        else printf("\n");
    }
    return 0;

}
