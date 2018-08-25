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
int a[115][115];
int dfs(int x,int y)
{
    int k;
    for(k=1;;k++)
    {
        int flag=1;
        for(int i =0;i<k&&flag;i++)
            for(int j =0;j<k&&flag;j++)
        {
            if(i+x>=n||j+y>=m){flag=0;break;}
            if(a[i+x][j+y]==0){flag=0;break;}
        }
        if(flag==0)break;
    }
    return k-1;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m)
    {
        for(int i =0;i<n;i++)
            for(int j =0;j<m;j++)
                cin>>a[i][j];
                int ans=0;
        for(int i =0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)continue;
           // if(i!=0&&a[i-1][j]==1)continue;
           // if(j!=0&&a[i][j-1]==1)continue;
           // if(i!=0&&j!=0&&a[i-1][j-1]==1)continue;
            ans=max(dfs(i,j),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
