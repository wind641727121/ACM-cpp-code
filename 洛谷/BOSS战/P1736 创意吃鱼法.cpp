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
#define bug1(g) cout<<"test: "<<g<<endl
#define bug2(g,i) cout<<"test: "<<g<<" "<<i<<endl
#define bug3(g,i,k) cout<<"test: "<<g<<" "<<i<<" "<<k<<endl
#define mem(ha,x) memset(ha,x,sizeof ha)
using namespace std;
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}

typedef long long ll;
int n,m,t;
int a[2505][2505];
int dp[2505][2505];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m)
    {
        mem(dp,0);
        for(int i =1;i<=n;i++)
            for(int j =1;j<=m;j++)
                cin>>a[i][j];
        //dp[1][1]=a[1][1];
        int maxx=0;
        for(int i =1;i<=n;i++)
            for(int j =1;j<=m;j++)
        {
           // int b=min(i,j);
            if(i==1||j==1)dp[i][j]=a[i][j];
            else
            {
                if(dp[i-1][j-1]==0||a[i][j]==0)dp[i][j]=a[i][j];
                else{
                        int flag=0;
                        for(int k =1;k<=dp[i-1][j-1];k++)
                            {if(dp[i-k][j]==0&&dp[i][j-k]==0)continue;
                            else {flag=k;break;}}
                        if(flag)dp[i][j]=flag;
                        else dp[i][j]=dp[i-1][j-1]+1;
                }

            }
             maxx=max(maxx,dp[i][j]);
        }

        mem(dp,0);
        for(int i =n;i>=1;i--)
            for(int j =1;j<=m;j++)
        {
            //int b=min(i,j);
            if(i==n||j==1) dp[i][j]=a[i][j];
            else
            {
                if(dp[i+1][j-1]==0||a[i][j]==0)dp[i][j]=a[i][j];
                else{
                        int flag=0;
                        for(int k =1;k<=dp[i+1][j-1];k++)
                            {if(dp[i+k][j]==0&&dp[i][j-k]==0)continue;
                            else {flag=k;break;}}
                        if(flag)dp[i][j]=flag;
                        else dp[i][j]=dp[i+1][j-1]+1;
                    }

            }
             maxx=max(maxx,dp[i][j]);
        }
        cout<<maxx<<endl;
    }
    return 0;
}
