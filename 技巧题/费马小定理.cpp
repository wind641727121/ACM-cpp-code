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
#define bug() cout<<123213<<endl
// (a^b)%p=a^[b%(p-1)]%p
typedef long long ll;
int n,m,t;
q/*ll poww(ll a,ll b,ll mod)
{
    ll ans =1;
    while(b)
    {
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%p;
    }
    return ans;
}*/
#define Mod 1000000007
int exp(int a,int b,int mod)
{
    int ans=1,base=a;
    while(b)
    {
        if(b&1)
            ans=((long long)ans*base)%mod;
        base=((long long)base*base)%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        int n=exp(b,c,Mod-1);
        printf("%d\n",exp(a,n,Mod));
    }
    return 0;
}
