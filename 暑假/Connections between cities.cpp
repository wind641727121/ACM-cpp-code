
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 20005
struct node{
    int u,v,d;
    int next;
}edge[2*N];
int num,n,head[N];
int root[2*N],rank[N];
int dep[2*N],dis[N];
int dp[2*N][30],vis[N];
int set[N];
void addedge(int u,int v,int d)
{
    edge[num].u=u;
    edge[num].v=v;
    edge[num].d=d;
    edge[num].next=head[u];
    head[u]=num++;
}
int Min(int a,int b)
{
    return dep[a]<dep[b]?a:b;
}
int find(int x)
{
    if(set[x]!=x)
        set[x]=find(set[x]);
    return set[x];
}
void merge(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x>y) set[x]=y;
    else set[y]=x;
}
void dfs(int u,int deep)
{
    vis[u]=1;
    root[++num]=u;
    rank[u]=num;
    dep[num]=deep;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v,d=edge[i].d;
        if(vis[v]) continue;
        dis[v]=dis[u]+d;
        dfs(v,deep+1);
        root[++num]=u;
        dep[num]=deep;
    }
}
void init()
{
    int nn=2*n-1;
    int m=(int)(log(nn*1.0)/log(2.0));
    for(int i=1;i<=nn;i++)
        dp[i][0]=i;
    for(int j=1;j<=m;j++)
        for(int i=1;i+(1<<j)-1<=nn;i++)
            dp[i][j]=Min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int RMQ(int l,int r)
{
    int m=(int)(log((r-l+1)*1.0)/log(2.0));
    return Min(dp[l][m],dp[r-(1<<m)+1][m]);
}
int LCA(int u,int v)
{
    int a=rank[u];
    int b=rank[v];
    if(a>b) return root[RMQ(b,a)];
    else return root[RMQ(a,b)];
}
int main(void)
{
    int m,c,u,v,d;
    int in[N];
    while(scanf("%d%d%d",&n,&m,&c)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        memset(in,0,sizeof(in));
        for(int i=0;i<=n;i++) set[i]=i;
        num=0;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&d);
            addedge(u,v,d);
            addedge(v,u,d);
            in[v]++;
            merge(u,v);
        }
        for(int i=1;i<=n;i++) //连接森林的所有树
            if(in[i]==0){
                addedge(0,i,0);
                addedge(i,0,0);
            }
        num=0;
        dis[0]=0;
        dfs(0,1);
        init();
        //for(int i=1;i<=2*n-1;i++) printf(i==2*n-1?"%d\n":"%d ",root[i]);
        //for(int i=1;i<=2*n-1;i++) printf(i==2*n-1?"%d\n":"%d ",dep[i]);
        //for(int i=1;i<=2*n-1;i++) printf(i==2*n-1?"%d\n":"%d ",dis[i]);
        //for(int i=1;i<=2*n-1;i++) printf(i==2*n-1?"%d\n":"%d ",rank[i]);
        while(c--){
            scanf("%d%d",&u,&v);
            //printf("*%d %d\n",find(u),find(v));
            if(find(u)!=find(v)) puts("Not connected");
            else printf("%d\n",dis[u]+dis[v]-2*dis[LCA(u,v)]);
        }
    }
    return 0;
}
