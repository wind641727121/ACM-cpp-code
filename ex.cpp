#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include<iostream>
using namespace std;
#define maxn 100005
#define maxm 200005
int n,m;
struct edge
{
    int dest;
    long long dist;
    struct edge*next;
}e[maxm],*head[maxn];
int pre[maxn];
int cnt;
inline void addedge(int u,int v,int w){
    e[cnt].next=head[u];
    e[cnt].dist=w;
    e[cnt].dest=v;
    head[u]=e+cnt++;
}
struct qnode
{
    int id;long long dist;
    qnode(int i,long long d){id=i,dist=d;}
    bool operator<(const struct qnode r)const{return dist>r.dist;}
};
bool vis[maxn];
long long dist[maxn];
void dijkstra(int src,int n)
{
    memset(vis,false,sizeof vis);
    memset(dist,0x3f,sizeof dist);  ///inf
    std::priority_queue<struct qnode>q;
    dist[src]=0;q.push(qnode(src,0));
    while(q.size()){
        int u=q.top().id;q.pop();vis[u]=true;
        for(struct edge*ptr=head[u];ptr;ptr=ptr->next){
            int v=ptr->dest;
            if(vis[v])continue;
            long long w=ptr->dist;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pre[v] = u;
                q.push(qnode(v,dist[v]));
            }
        }
    }
}
void init()
{
	cnt = 0;
	memset(head, 0, sizeof(head));
	memset(pre, -1, sizeof(pre));
}
void getMap()
{
	int a, b, c;
	while(m--)
	{
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);
	}
}
int  k;
stack<int> path;
 priority_queue <int,vector<int>,greater<int> > q;
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
    while(t--){
  //  memset(wr,0,sizeof wr);
	scanf("%d%d%d",&n, &m,&k);
    init();
    getMap();
   dijkstra(1,n);
  //  cout<<123<<endl;
    path.push(n);
    int now = pre[n];
    while(1)
    {
        path.push(now);
        if(now == 1)
        break;
        now = pre[now];
    }
    int last=1;
    path.pop();
    //cout<<dist[n]<<endl;
    while(!path.empty())
    {
        for(struct edge*ptr=head[last];ptr;ptr=ptr->next)
       {
          cout<< "teste"<<" "<<path.top()<<endl;
           if(path.top()==ptr->dest){
                 cout<<last<<" "<<ptr->dest<<" "<<ptr->dist<<endl;
                if(q.size()<k) q.push(ptr->dist);
                else{
                    if(ptr->dist>q.top()) {q.pop();q.push(ptr->dist);}
                    else break;
                }
                break;
           }
       }
       last=path.top();
        path.pop();
    }
    while(!q.empty())
        {dist[n]-=q.top();q.pop();}
    cout<<dist[n]<<endl;
		}
	}
	return 0;
}
