#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005*4];
ll w,h,n;
void make(ll rt,ll l,ll r)
{
    a[rt]=w;
    if(l==r) return;
    ll mid=(l+r)/2;
    make(rt*2,l,mid);
    make(rt*2+1,mid+1,r);
}
ll q(ll rt,ll l,ll r,ll x)
{
    if(l==r)
    {
        a[rt]=a[rt]-x;
       // cout<<a[rt]<<" "<<l<<endl;
        return l;
    }
    ll mid=(l+r)/2,res;
    if(x<=a[rt*2])
        res=q(rt*2,l,mid,x);
    else res=q(rt*2+1,mid+1,r,x);
    a[rt]=max(a[rt*2],a[rt*2+1]);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    while (cin>>h>>w>>n)
    {
        h=min(n,h);
        memset(a,0,sizeof a);
        make(1,1,h);
        for(int i =1;i<=n;i++)
        {
            int ha;
            cin>>ha;
            //cout<<a[1]<<endl;
            if(ha>a[1])  cout<<-1<<endl;
            else cout<<q(1,1,h ,ha)<<endl;
        }
    }
   return 0;
}
