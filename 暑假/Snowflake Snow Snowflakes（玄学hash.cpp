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
typedef long long ll;
int n,m,t;
vector<int>a[99983];
int b[100005][7];
int ok(int i,int ans)
{
    int flag=0;
    for(int x =0;x<a[ans].size();x++)
    {
        if(flag)break;
        int k=a[ans][x];
        for(int j =0;j<6;j++)
        {
            if(flag)break;
            if(b[k][0]==b[i][j])
            {
                int g =0;
                for(int l=0;l<6;l++)
                {
                    if(b[k][l]==b[i][(j+l)%6]) g++;
                    else break;
                }
                if(g==6){flag=1;break;}
                g=0;
                int ha=j;
                for(int l=0;l<6;l++)
                {
                    if(b[k][l]==b[i][(ha-l)%6]) {g++; if(j-l==0) ha+=6;}
                    else break;
                }
                if(g==6){flag=1;break;}
            }
        }
    }
    return flag;
}
int main()
{
  //  ios::sync_with_stdio(0);
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        for(int i =0;i<99983;i++) a[i].clear();
        for(int i =0;i<n;i++)
        {
            ll ans=0;
            for(int j =0;j<6;j++)
            {
                scanf("%d",&b[i][j]);
                ans=(ans+b[i][j])%99983;
            }
            if(flag)continue;
            if(a[ans].size())
            {
                if(ok(i,ans)) flag=1;
                else a[ans].push_back(i);
            }
            else
            {
                a[ans].push_back(i);
            }
        }
        if(flag) printf("Twin snowflakes found.\n");
        else printf("No two snowflakes are alike.\n");
    }
    return 0;
}
