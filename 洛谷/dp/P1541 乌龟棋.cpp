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
int a[500]={0},b[5]={0};
int d[45][45][45][45]={0};
int n,m,t;
int dfs(int s,int p1,int p2,int p3,int p4)
{
   // cout<<s<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
    if(s==n) return 0;
   // if(d[p1][p2][p3][p4]) return d[p1][p2][p3][p4];
    int ans=-1;
    if(b[1]>p1)
        ans=max(ans,dfs(s+1,p1+1,p2,p3,p4)+a[s+1]);
    if(b[2]>p2)
        ans=max(ans,dfs(s+2,p1,p2+1,p3,p4)+a[s+2]);
    if(b[3]>p3)
        ans=max(ans,dfs(s+3,p1,p2,p3+1,p4)+a[s+3]);
    if(b[4]>p4)
        ans=max(ans,dfs(s+4,p1,p2,p3,p4+1)+a[s+4]);
    return d[p1][p2][p3][p4]=ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i =1;i<=n;i++) cin>>a[i];
    int k;
    for(int i =0;i<m;i++)
    {
        cin>>k;
        ++b[k];
    }
    cout<<dfs(1,0,0,0,0)+a[1]<<endl;
    return 0;
}
