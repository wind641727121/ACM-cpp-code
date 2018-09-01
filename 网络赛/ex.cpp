#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pb push_back
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f

using namespace std;

typedef long long ll;
const ll MOD=100000000;
const ll MAXN=2e7+20;
vector<int> prim;
int isprim[MAXN];
int dp[MAXN];
vector<int> sq;
int sq2[MAXN];
ll sum[MAXN];
int main(){
    std::ios::sync_with_stdio(0);
    ll i,j,k,t1,t2,t3,t4,n,m,t;
    memset(isprim,-1,sizeof(isprim));
    memset(dp,0,sizeof(dp));
    prim.clear();
    for (i=2;i<2e7+5;i++){
        if (isprim[i]==-1){
            prim.pb(i);
             dp[i]=2;
        }
           for (j=0;j<prim.size()&&prim[j]*i<MAXN;j++){
            isprim[i*prim[j]]=prim[j];
            if (i%prim[j]==0)
                break;
           }
    }
    cin>>t;
    sq.clear();
    for (i=0;i<prim.size();i++){
            t1=prim[i];
            t2=prim[i];
            if ((ll)t1*(ll)t1>=2e7+5)break;
            while (t1<=2e7+5){
                t1*=t2;
                if (t1<=2e7+5)
                   {
                       sq.pb(t1);
                       sq2[t1]=1;
                       if (t1==prim[i]*prim[i])
                        dp[t1]=1;
                       else dp[t1]=0;

                   }
            }
    }
    for (i=0;i<prim.size();i++)
    for (j=i+1;j<prim.size();j++){
        if ((ll)prim[i]*(ll)prim[j]>=2e7+5)
            break;
        dp[prim[i]*prim[j]]=dp[prim[i]]*dp[prim[j]];
    }
    t1=prim.size();
    t2=sq.size();
    for (i=0;i<sq.size();i++){
        for (j=0;j<prim.size();j++){
            if ((t4=(ll)prim[j]*(ll)sq[i])>2e7+5)
                break;
            if (sq2[t4])
                continue;
            dp[prim[j]*sq[i]]=dp[prim[j]]*dp[sq[i]];
            }
    }
    dp[1]=1;
    for (i=2;i<=2e7+5;i++)
        if (!sq2[i]&&isprim[i]!=-1){
            t4=i;
            t3=1;
            while ((t4%isprim[i])==0){
                t4/=isprim[i];
                t3*=isprim[i];
            }
            dp[i]=dp[t3]*dp[t4];
        }
    memset(sum,0,sizeof(sum));
    for(i=1;i<2e7+5;i++)
        sum[i]=sum[i-1]+dp[i];
   while (t--){
        cin>>n;
        if (n<=0)
            cout<<0<<'\n';
        else
        cout<<sum[n]<<'\n';
    }
}
