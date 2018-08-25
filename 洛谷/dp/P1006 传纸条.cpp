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
int n,m,t;
int a[100][100],dp[60][60][60][60];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m)
    {
        for(int i =1;i<=n;i++)
            for(int j =1;j<=m;j++)
        {
            cin>>a[i][j];
        }
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
            for(int j =1;j<=m;j++)
                for(int k =1;k<=n;k++)
                    for(int l=1;l<=m;l++)
        {
            if(i==1&&j==1&&k==1&&l==1)continue;
            int ha=dp[i][j][k][l];
            ha=max(dp[i][j-1][k-1][l],ha);
            ha=max(dp[i][j-1][k][l-1],ha);
            ha=max(dp[i-1][j][k-1][l],ha);
            ha=max(dp[i-1][j][k][l-1],ha);
            dp[i][j][k][l]=ha+a[i][j]+a[k][l];
            if(i==k&&j==l)dp[i][j][k][l]-=a[k][l];
        }
        cout<<dp[n][m][n][m]<<endl;

    }
    return 0;
}
