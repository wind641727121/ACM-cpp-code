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
typedef long long ll;
const int  N=10005;
int n,m,t,q;
vector<int>son[10005];
vector<int>dis[10005];
int T,depth[N],fa[N],in[N],a,b,c;
int f[N];
int find(int x)
{
    while(x!=f[x]) x=f[x];
        return x;
}
void combine(int a,int b)
{
    int fa1=find(a),fb=find(b);
    if(fa1!=fb)
    {
        f[fb]=fa1;
    }
}
void dfs(int pre,int rt)
{
    depth[rt]=depth[pre]+1;
    fa[rt]=pre;
    for(int i =0;i<son[rt].size();i++)
    {
        dfs(rt,son[rt][i]);
    }
}
int lca(int a,int b)
{
    int ans=0;
    bug1(ans);
    if(depth[a]>depth[b]) swap(a,b);
    bug1(ans);
    while(depth[b]>depth[a]) {ans+=dis[fa[b]][b],b = fa[b],bug1(ans);}
    while(a!=b) {ans+=(dis[fa[b]][b]+dis[fa[a]][a]),a=fa[a],b=fa[b],bug1(ans);}
    return ans;
}
int vis[N];
int main()
{
   // ios::sync_with_stdio(0);
    while(~scanf("%d %d %d",&n,&m,&q))
    {
            for(int i=1;i<=n;i++)
                f[i]=i;
            memset(vis,0,sizeof vis);
            for(int i =1;i<=n;i++) son[i].clear();
            memset(in,0,sizeof in);
            for(int i =1;i<=m;i++)
            {
                scanf("%d %d %d",&a,&b,&c);
                combine(a,b);
                son[a].push_back(b);
                dis[a].push_back(c);

            }
            depth[0]=-1;
            int rt=0;
            for(int i =1;i<=n;i++)
                    if(in[i]==0)
                        dfs(0,i);
            for(int i =0;i<q;i++)
               {
                    scanf("%d %d",&a,&b);
                    if(find(a)!=find(b)) cout<<"Not connected"<<endl;
                    else cout<<lca(a,b)<<endl;
               }
    }
    return 0;
}
