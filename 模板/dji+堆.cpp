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
//����С��Ԫ�ط��ڶ��׵����ȶ���
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    //��仰���ڴ��ⲻ��Ҫ����������֮������⻹�����õ�
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    //�洢�õ����һ����
    head[u]=cnt;
    //����Ŀǰ�õ�����һ���ߣ�������һ���ߣ�
}
//��ʽǰ���Ǽӱ�
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    //����ֵ
    q.push(make_pair(0,s));
    while(!q.empty())
    //��Ϊ�ռ�Ϊ���е㶼����
    {
        int x=q.top().second;
        q.pop();
        //��¼�Ѷ������䵯��
        if(!vis[x])
        //û�б���������Ҫ����
        {
            vis[x]=1;
            for(int i=head[x];i;i=e[i].next)
            //�����Ѷ���������
            {
                int v=e[i].v;
                dis[v]=min(dis[v],dis[x]+e[i].w);
                //�ɳڲ���
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
