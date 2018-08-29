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
typedef long long ll;
vector<int>son[6005];
int n,m,t,r[6005],in[6005];
int dp[6005][2];
void dfs(int rt)
{
    int max1=0,max0=0;
    for(int i =0;i<son[rt].size();i++)
        {
            dfs(son[rt][i]);
            max1+=dp[son[rt][i]][0];
            max0+=max(dp[son[rt][i]][0],dp[son[rt][i]][1]);
        }
    dp[rt][0]=max0;
    dp[rt][1]=max1+r[rt];
}
int main()
{
  //  ios::sync_with_stdio(0);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i =1;i<=n;i++)
            scanf("%d",&r[i]),son[i].clear();
        int a,b;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
            if(a==0&&b==0) break;
            son[b].push_back(a);
            ++in[a];
        }
        int rt;
        for(int i =1;i<=n;i++)
        {
            if(in[i]==0){rt=i;break;}
        }
         dfs(rt);
         cout<<max(dp[rt][0],dp[rt][1])<<endl;
    }
    return 0;
}
