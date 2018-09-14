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
struct edge{
int u,v,w;
friend bool operator <(edge a,edge b){return a.w>b.w;}
}a[50005];
typedef long long ll;
int n,m,t,r;
int f[100005];
void init()
{
    for(int i =0;i<=n+m;i++) f[i]=i;
}
int findd(int x)
{
    return f[x]==x?x:f[x]=findd(f[x]);
}
void unio(int a,int b)
{
    int x=findd(a),y=findd(b);
    if(x==y)return;
    f[x]=y;
}
int main()
{
    //ios::sync_with_stdio(0);
      t=read();
        while(t--)
        {
            n=read();m=read();r=read();
            init();
            for(int i =0;i<r;i++)
            {
                a[i].u=read();a[i].v=read();a[i].w=read();
                a[i].v+=n;
                //a[i].r=-a[i].r;
            }
            int ans=10000*(n+m);
            sort(a,a+r);
            for(int i =0;i<r;i++)
            {
                int u =a[i].u,v=a[i].v;
                if(findd(u)==findd(v))continue;
                else
                {
                    ans-=a[i].w;
                    unio(u,v);
                }
            }
            cout<<ans<<endl;
        }

    return 0;
}
