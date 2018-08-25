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
int n,m,t,k;
struct node
{
    int x,y,d;
}a[1000];
bool cmp(node a,node b)
{
    return a.d>b.d;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m>>k)
    {
        memset(a,0,sizeof a);
        int t =0;
        int ha=0;
        for(int i =1;i<=n;i++)
            for(int j =1;j<=m;j++)
                {

                    a[t].x=i,a[t].y=j;
                    cin>>a[t++].d;
                    if(i==1)ha=max(ha,a[t-1].d);
                }
        sort(a,a+t,cmp);
        int ans=0,num=0;k=k-2;
        if(n==1&&m==1&&k==3){cout<<ha<<endl;break;}
        int x=1,y=a[0].y;
        while(k&&num<t-1)
        {

            int d=abs(a[num].x-x)+abs(a[num].y-y);
           // cout<<k<<" "<<d<<endl;
            if(k>=d+1+a[num].x-1) {k-=(d+1);ans+=a[num].d;x=a[num].x,y=a[num++].y;}
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
