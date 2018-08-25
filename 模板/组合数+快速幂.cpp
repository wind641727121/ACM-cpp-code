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
const int mod=998244353;
typedef long long ll;
ll poww(ll a,ll b)
{
    ll ans=1,base=a;
    while(b!=0)
    {
        if(b&1!=0)
            ans=(ans*base)%mod;
        base =(base*base)%mod;
        b>>=1;
    }
    return ans;
}
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0&&b==0)
        return -1;//无最大公约数
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll mod_reverse(ll a,ll n)
{
    ll x,y;
    ll d=extend_gcd(a,n,x,y);
    if(d==1)
        return (x%n+n)%n;
    else
        return -1;
}
ll c(ll m,ll n)
{
    if(m>n)
        return 0;
    ll i,j,t1,t2,ans;
    t1=t2=1;
    for(i=n; i>=n-m+1; i--)
        t1=t1*i%mod;
    for(i=1; i<=m; i++)
        t2=t2*i%mod;
    return  t1*mod_reverse(t2,mod)%mod;
}
int t,n,q;
ll a,b,cc,d,ans;

