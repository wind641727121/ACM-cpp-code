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
struct edge
{
    int u,v,w;
    friend bool operator <(edge a,edge b){return a.w<b.w;}
}e[200005];
typedef long long ll;
int n,m,t;
int f[5005];
void init()
{
    for(int i =0;i<=n;i++)f[i]=i;
}
int findd(int x)
{
    return f[x]==x?x:f[x]=findd(f[x]);
}
void unio(int a,int b)
{
    int x= findd(a),y=findd(b);
    if(x==y)return ;
    f[x]=y;
}
bool vis[5005];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i =0;i<m;i++)
    {
        //int a,b,c;
        cin>>e[i].u>>e[i].v>>e[i].w;
        vis[e[i].u]=vis[e[i].v]=1;
    }
    sort(e,e+m);
    int ans=0;
    init();
    for(int i =0;i<m;i++)
    {
        if(findd(e[i].u)!=findd(e[i].v))
        {
            ans+=e[i].w;
            unio(e[i].u,e[i].v);
        }
    }
    int flag=-1;
    for(int i =0;i<=n;i++)
    {
        if(vis[i]) {if(flag==-1||flag==f[i])flag=f[i];
                    else flag=-1;break;}

    }
    if(flag==-1) cout<<"orz"<<endl;
    else cout<<ans<<endl;
    return 0;
}
