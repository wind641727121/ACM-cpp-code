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
    ll x,y;
   bool operator < (node a){
       if(x!=a.x)return x<a.x;
       else return y<a.y;
       }
}a[20005];
bool cmp1(node a,node b)
{
    return min(a.x,b.y)<min(a.y,b.x);
}

int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            for(int i = 0;i<n;i++)
            {
                cin>>a[i].x>>a[i].y;
            }
            sort(a,a+n,cmp1);
            ll last ,sum=0,maxx=-1;
            for(int i =0;i<n;i++)
            {
                if(i==0) last=a[i].x+a[i].y,sum+=a[i].x;
                else
                {
                     sum+=a[i].x;
                    last = max(last,sum)+a[i].y;
                }
                maxx=max(maxx,last);
            }
            cout<<maxx<<endl;

        }
    }
    return 0;
}
