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
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
ll flag=0,num=0,d,m;
ll a[200005];
inline ll lowbit(ll x)
{
    return -x&x;
}
void add(ll n)
{
    ll maxx=(n+flag)%d,x=num;
    while(x>0)
    {
        a[x]=max(maxx,a[x]);

        x-=lowbit(x);
    }
}
ll sum(ll x)
{
    ll ans=-(1<<63);
    while(x<=num)
    {
   //      bug2(a[x],ans);
        ans=max(ans,a[x]);
        x+=lowbit(x);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
     cin>>m>>d;
     num=flag=0;
     memset(a,0,sizeof a);
     for(int i =0;i<m;i++)
     {
         char c;ll b;
         cin>>c>>b;
         if(c=='A') ++num,add(b);
         else  {flag=sum(num-b+1);cout<<flag<<endl;}
     }
    return 0;
}
