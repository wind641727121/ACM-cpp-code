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
int n,m,t;
int a[5005];
struct node
{
    int v;
    vector<int> pre;
    node(){v=1;}
}dp[5005];
int dfs(int n)
{
    int ans=0;
    if(dp[n].pre.empty()) return 1;
    for(int i=0;i<dp[n].pre.size();i++)
    {
        ans+=dfs(dp[n].pre[i]);
    }
   // ans*=dp[n].pre.size();
    return ans;
}
int main()
{
    //ios::sync_with_stdio(0);
    n=read();
    //dp[0].v=1;
    for(int i=0;i<n;i++) a[i]=read();
    a[n]=-1;
    int maxx=-1,ans=1;
    for(int i =0;i<=n;++i)
    {
        //dp[i].pre.clear();
        for(int j =i-1;j>=0;--j)
            if(a[j]>a[i]&&dp[j].v+1>=dp[i].v)
            {
                int flag=0;
                if(dp[j].v+1>dp[i].v) dp[i].pre.clear();
                dp[i].v=dp[j].v+1;
                for(int k=0;k<dp[i].pre.size();k++)
                if(a[j]==a[dp[i].pre[k]]){flag=1;break;}
                if(flag==0)dp[i].pre.push_back(j);
            }
        //maxx=max(maxx,dp[i].v);
    }
    maxx=dp[n].v-1;
    cout<<maxx<<" "<<dfs(n)<<endl;
    return 0;
}
