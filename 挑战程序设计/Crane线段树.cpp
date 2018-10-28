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
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

typedef long long ll;
int n,m,t;
struct node{
int w;
int mark;
}tr[1000<<2];
void build(int rt,int l,int r)
{
    tr[rt].mark=0;
    if(l==r)
    {
        tr[rt].w==read();
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    tr[r].w=min(tr[r<<1].w,tr[1+r<<1].w);
}
void pushdown(int r)
{
    tr[r<<1].w+=tr[r].mark;
    tr[1+r<<1].w+=tr[r].mark;
    tr[r<<1].mark+=tr[r].mark;
    tr[r<<1+1].mark+=tr[r].mark;
    tr[r].mark=0;
}
int q(int rt,int l,int r,int ql,int qr)
{
    if(l>qr||ql>r) return 0x3f3f3f;
    if(l>=ql&&r<=qr) return tr[r].w;
    if(tr[rt].mark) pushdown(rt);
    int mid=(l+r)>>1;
    return min(q(lson,ql,qr),q(rson,ql,qr));
}
int up()
{

}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {

        }
    }
    return 0;
}
