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
typedef long long ll;
ll n,m,t,inv[3000055],mod;
void inverse()
{
    memset(inv,0,sizeof(inv));
    inv[1]=1;
    for (ll i=2;i<=n;i++)
    {
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    }
}
int main()
{

    while(scanf("%lld %lld",&n,&mod)!=EOF)
    {
        inverse();
        for(ll i =1;i<=n;i++)
            printf("%lld\n",inv[i]);
    }
    return 0;
}
