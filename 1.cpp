#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll MAXN=1e4+5;
const ll mod=998244353;
ll l[MAXN];
ll r[MAXN];
ll p[MAXN];
ll fast_pow(ll a,ll b){
    ll ans=1;
    while (b){
        if (b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll rev(ll a){
    return fast_pow(a,mod-2);
}
int main(){
    std::ios::sync_with_stdio(0);
    ll t,i,j,k,t1,t2,t3,n,m,rm,lm;
    cin>>t;
    while (t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=0;
        ans=fast_pow(2,a+b);
        t1=fast_pow(2,a+c);
        t1=(t1*(1+b+d))%mod;
        ans=(ans+t1)%mod;
        t1=fast_pow(2,a);
        t1=(t1*(b+1))%mod;
        ans=(ans+mod-t1)%mod;
        cout<<ans<<'\n';
    }
}
