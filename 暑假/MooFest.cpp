#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,t,maxx;
ll t1[20005];//geshu
ll t2[20005];//he
struct cow
{
    ll v,x;
}a[20005];
bool cmp(cow a,cow b){return a.v<b.v;}
ll lowbit(ll x){return x&(-x);}
ll sum(ll i,ll t[])
{
  ll res=0;
  while(i>0)
  {
      res+=t[i];
      i-=lowbit(i);
  }
  return res;
}
void up(ll i,ll x,ll t[])
{
  while(i<=maxx)
  {
    t[i]+=x;
    i+=lowbit(i);
  }
}
int main()
{
    ios::sync_with_stdio(0);
    while (cin>>n)
    {

        maxx=-1;
        for(int i =1;i<=n;i++)
            {cin>>a[i].v>>a[i].x;maxx=max(maxx,a[i].x);}
        sort(a+1,a+1+n,cmp);
        memset(t1,0,sizeof t1);
        memset(t2,0,sizeof t2);
         ll Sum=0;
        for(int i =1;i<=n;i++)
        {
            ll cn=sum(a[i].x,t1);
            ll cs=sum(a[i].x,t2);
            ll s=sum(maxx,t2);
          //  cout<<a[i].x<<" "<<a[i].v<<" "<<cn<<" "<<cs<<" "<<s<<" ";
            Sum+=a[i].v*(cn*a[i].x-cs+(s-cs)-(i-cn-1)*a[i].x);
            //cout<<Sum<<endl;
           up(a[i].x,1,t1);
           up(a[i].x,a[i].x,t2);
        }
        cout<<Sum<<endl;

    }
   return 0;
}
