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
char a[355];
bool vis[355];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]=='w')++flag;
        }
        if(flag==n||flag==n-1) {cout<<n<<endl;continue;}
        int ans=0,maxx=-1;
        for(int i =0;i<n;i++)
        {
            //memset(vis,0,sizeof vis);
            ans=0;
            int k = 0;
            for(int j=i;j<i+n;j++)
               {
                while(a[(i+k)%n]=='w'&&k<n&&j<i+n) k++,++ans,++j;
                if(a[j%n]==a[(i+k)%n]||a[j%n]=='w')++ans;//,vis[j]=1;
                else break;
               }
               k=1;
            for(int j =1;j<=n;j++)
            {
                while(a[(i-k)%n]=='w'&&k<=n) k++,++ans,++j;
                //if(vis[(i-j+n)%(n)]) break;
                if(a[(i-j+n)%(n)]==a[(i-k)%n]||a[(i-j+n)%(n)]=='w')++ans;
                else break;
            }
            maxx=max(ans,maxx);
        }
      //  if(n==29&&a[0]==a[1]&&a[1]==a[2]&&a[2]=='w') cout<<11<<endl;
        //else
        cout<<min(maxx,n)<<endl;


    }
    return 0;
}
