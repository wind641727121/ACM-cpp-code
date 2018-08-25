#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
//long long a[100005]={1, 0, 0, 1, 1};
struct node
{
    int p,s;
    int vis;
    node(int a=0,int b=0, int c=0){p=a,s=b,vis=c;}
}a[100];
vector<node>b[100];
int dp[33000];
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin>>m>>n;
    for(int  i=1;i<=n;i++)
    {
        b[i].clear();
        int x,y,z;
        cin>>x>>y>>z;
        if(z==0)
        {
            a[i].p=x,a[i].s=y,a[i].vis=0;
        }
        else
        {
            a[i].vis=z;
            b[z].push_back(node(x,y,0));
        }
    }
        memset(dp,0,sizeof dp);
        for(int i =1;i<=n;i++)
        {
            if(a[i].vis!=0){continue;}
            for(int j=m;j>=a[i].p;j--)
            {

                if(b[i].size()==0)
                    dp[j]=max(dp[j],dp[j-a[i].p]+a[i].p*a[i].s);
                else if(b[i].size()==1)
                {
                    dp[j]=max(dp[j],dp[j-a[i].p]+a[i].p*a[i].s);
                    if(j-a[i].p-b[i][0].p>=0)
                    {
                        dp[j]=max(dp[j],dp[j-a[i].p-b[i][0].p]+b[i][0].p*b[i][0].s+a[i].p*a[i].s);
                    }
                }
                else if(b[i].size()==2)
                {
                    dp[j]=max(dp[j],dp[j-a[i].p]+a[i].p*a[i].s);
                    if(j-a[i].p-b[i][0].p>=0)
                    {
                        dp[j]=max(dp[j],dp[j-a[i].p-b[i][0].p]+b[i][0].p*b[i][0].s+a[i].p*a[i].s);
                    }
                    if(j-a[i].p-b[i][1].p>=0)
                        dp[j]=max(dp[j],dp[j-a[i].p-b[i][1].p]+b[i][1].p*b[i][1].s+a[i].p*a[i].s);
                    if(j-a[i].p-b[i][1].p-b[i][0].p>=0)
                        dp[j]=max(dp[j],dp[j-a[i].p-b[i][1].p-b[i][0].p]+b[i][1].p*b[i][1].s+b[i][0].p*b[i][0].s+a[i].p*a[i].s);


                }
              //   cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
             //getchar();
        }

         cout<<dp[m]<<endl;

    return 0;

}
