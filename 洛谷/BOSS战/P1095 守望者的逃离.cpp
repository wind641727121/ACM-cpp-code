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
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

typedef long long ll;
ll s;
int t,m;
int dp[300005];
int main()
{
    ios::sync_with_stdio(0);
        cin>>m>>s>>t;
        dp[0]=0;
        for(int i =1;i<=t;i++)
        {
            if(m>=10)dp[i]=dp[i-1]+60,m-=10;
            else{
                dp[i]=dp[i-1];m+=4;
            }
        }
        for(int i =1;i<=t;i++)
        {
            dp[i]=max(dp[i],dp[i-1]+17);
            if(dp[i]>=s)
            {
                cout<<"Yes"<<endl<<i<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl<<dp[t]<<endl;

    return 0;
}

