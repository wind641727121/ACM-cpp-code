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
int n,m,t;
struct node
{
    int l,w;
}a[5005];
bool cmp(node a,node b)
{
    if(a.l!=b.l)return a.l<b.l;
    else return a.w<b.w;
}
int vis[5005];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n)
    {
        memset(vis,0,sizeof vis);
        for(int i =0;i<n;i++)
            cin>>a[i].l>>a[i].w;
        sort(a,a+n,cmp);
        int ans = 0,lw=-1;
        for(int i =0;i<n;i++)
        {
            if(vis[i])continue;
            else
            {
                ++ans;
                vis[i]=1;
                lw = a[i].w;
                for(int j = i+1;j<n;j++)
                {
                    if(vis[j]==0&&a[j].w>=lw) {vis[j]=1;lw=a[j].w;}
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
