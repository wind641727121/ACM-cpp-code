#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define maxm 500005
#define INF  2147483647
inline int read(){
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
struct Edge
{
    int u,v,w,next;
}e[maxm];
int head[maxm],cnt,n,m,s,vis[maxn],dis[maxn];
#define P pair<long long,int>
priority_queue<P,vector<P>,greater<P> >q;
//把最小的元素放在队首的优先队列
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    //这句话对于此题不需要，但在缩点之类的问题还是有用的
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    //存储该店的下一条边
    head[u]=cnt;
    //更新目前该点的最后一条边（就是这一条边）
}
//链式前向星加边
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    //赋初值
    q.push(make_pair(0,s));
    while(!q.empty())
    //堆为空即为所有点都更新
    {
        int x=q.top().second;
        q.pop();
        //记录堆顶并将其弹出
        if(!vis[x])
        //没有遍历过才需要遍历
        {
            vis[x]=1;
            for(int i=head[x];i;i=e[i].next)
            //搜索堆顶所有连边
            {
                int v=e[i].v;
                dis[v]=min(dis[v],dis[x]+e[i].w);
                //松弛操作
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
int main()
{
    n=read(),m=read();s=read();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        add(x,y,z);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        printf("%d ",dis[i]);
    }
    return 0;
}
