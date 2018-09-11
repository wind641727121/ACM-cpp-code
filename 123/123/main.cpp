#include<iostream>
#include<queue>
#include<cstring>

#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
const ll MAXN=1e3+5;
const ll mod=1e9+7;
inline ll read(){
    ll s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //���Сϸ�ڣ�getchar()==-1ʱֱ��exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
ll fast_pow(ll a,ll b){
    ll ans=1;
    while (b){
        if (b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll mod_revese(ll a){
    return fast_pow(a,mod-2);
}
vector<ll> prim;
int main(){
    ll i,j,t1,t2,t3,t4,n,m,k,s,ee,t,t5;
    while (~scanf("%lld%lld",&n,&m)){
       ll sum=(((((n*(n+2))%mod)*(n+1))%mod)*mod_revese(3))%mod;
       prim.clear();
       t1=m;
       for (i=2;i*i<=t1;i++){
            if (t1%i==0){
                           prim.push_back(i);

            while (t1%i==0){
                t1/=i;
            }
            }
       }
       if (t1!=1)
        prim.push_back(i);
       for (i=0;i<(1<<prim.size());i++){
            t1=0;
            t2=1;
            for (j=0;j<prim.size();j++){
                if ((i)&(1<<j)){
                    t2*=prim[j];
                    t1++;
                }
            }
            if (t2==1)
                continue;
            t3=n/t2;
            t4=((((t3*(t3+1))%mod)*(2*t3+1))%mod);
            t4=(t4*mod_revese(6))%mod;
            t4=(((t4*t2)%mod)*t2)%mod;
            t5=(t3*(t3+1))%mod;
            t5=(((t5*t2)%mod)*mod_revese(2))%mod;
            t4=(t4+t5)%mod;
            if (t1%2)
                sum=(sum+mod-t4)%mod;
            else sum=(sum+t4)%mod;
       }
       printf("%lld\n",sum);
    }
}
