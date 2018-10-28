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
string a,b;
int dp[5005][5005];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            cin>>a>>b;
            memset(dp,0,sizeof dp);
            for(int i =1;i<=a.size();i++)
                for(int j =1;j<=b.size();j++)
{
                if(a[i-1]==b[j-1]) dp[i][j]=max(dp[i-1][j-1],dp[i][j])+1;
                else dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                //bug3(i,j,dp[i][j]);
            }
            cout<<dp[a.size()][b.size()]<<endl;
        }
    }
    return 0;
}
