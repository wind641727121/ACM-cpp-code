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
#define bug(g) cout<<g<<endl
typedef long long ll;
int n,m,t,s;
ll l;
int a[105]={0},d[105],st[252005]={0};
int dp[252005];
int main()
{
    ios::sync_with_stdio(0);
    cin>>l>>s>>t>>m;
    for(int i =1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    for(int i =1;i<=m;i++) d[i]=(a[i]-a[i-1])%2520;
    for(int i =1;i<=m;i++)
    {
        a[i]=a[i-1]+d[i];
        st[a[i]]=1;
    }
    l=a[m];
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    int ans=0x3f3f3f;
    for(int i =0;i<=l+t;i++)
    {``
        for(int j =s;j<=t;j++)
            if(i-j>=0)
                dp[i]=min(dp[i],dp[i-j]);
        dp[i]+=st[i];
        if(i>=l&&i!=l+t)
            ans=min(ans,dp[i]);
            //cout<<dp[i]<<endl;
    }
    if(ans==0x3f3f3f) cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}
