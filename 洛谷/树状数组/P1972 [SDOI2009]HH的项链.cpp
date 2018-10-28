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
int a[500005],t[500005],c[1000001];
struct node
{
    int l,r,i;
}m[500005];
int block;
bool cmp(node a,node b)
{
    if((a.l/block)==(b.l/block))
        return a.r<b.r;
    else return (a.l/block)<(b.l/block);
}
int n,tmp;
map<int,int> mp;
int main()
{
    n=read();
    for(register int i=1;i<=n;i++) a[i]=read();
    block=sqrt(n+0.5);
    n =read();
    for(register int i =0;i<n;i++)
        m[i].l=read(),m[i].r=read(),m[i].i=i;
    sort(m,m+n,cmp);
    register  int ans=0,l=0,r=0;
    a[0]=1000001;
    for(register int i =0;i<n;i++)
    {
       // bug3(l,r,ans);
        while(m[i].l<l){l--;++c[a[l]];if(c[a[l]]==1)++ans; }
        // bug3(l,r,ans);
        while(m[i].l>l){--c[a[l]];if(c[a[l]]==0)--ans;++l;}
        // bug3(l,r,ans);
        while(m[i].r>r){++r;++c[a[r]];if(c[a[r]]==1)++ans;}
       //  bug3(l,r,ans);
        while(m[i].r<r){--c[a[r]];if(c[a[r]]==0)--ans;--r;}
        t[m[i].i]=ans;
    }
    for(int i =0;i<n;i++) printf("%d\n",t[i]);
    return 0;
}
