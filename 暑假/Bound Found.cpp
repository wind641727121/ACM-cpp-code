#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<queue>
using namespace std;
typedef long long ll;
ll s[500005];
ll a[100005];
ll k,n,m;
struct node
{
    ll l,r,ans;
    node(){l=r=0;ans=-1;}
};
ll made(ll r,ll b,ll e)
{
    if(b==e) return s[r]=a[b];
    else{
       int mid =(b+e)/2;
        s[r]=made(r*2,b,mid)+made(r*2+1,mid+1,e);
        return s[r];
    }
}
ll q(ll r,ll b,ll e,ll c,node d)
{
    if(d.l==0&&d.r==0){d.l=b,d.r=e,d.ans=abs(s[r]);}
    if(abs(k-d.ans)>abs(k-abs(s[r]))) {d.l=b,d.r=e,d.ans=abs(s[r]);}
    if(b==e)return  return s[r].p;
    ll mid=(b+e)/2;
    if (abs(k-abs(q(r*2,b,mid,c,d)+q(r*2+1,mid+1,e,c,d)))<abs(k-d.ans))
    {
        d.l=b,d.r=e,d.ans=abs(q(r*2,b,mid,c,d)+q(r*2+1,mid+1,e,c,d));
    }
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
