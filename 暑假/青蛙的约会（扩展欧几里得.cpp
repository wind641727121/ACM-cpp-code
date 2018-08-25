#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<queue>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;x=y;y=t-a/b*y;
    return r;
}
ll x,y,m,n,l;
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>x>>y>>m>>n>>l)
    {
        ll a,b,c,d,xx,yy;
        a=m-n;b=l;d=y-x;
        if(a<0)a=-a,d=-d;
        c=exgcd(a,b,xx,yy);
        if(d%c!=0)cout<<"Impossible"<<endl;
        else{
           xx=xx*d/c;
            ll t= l/c;

            if(xx>=0)xx=(xx+t)%t;
            else xx=xx%t+t;
            cout<<xx<<endl;
        }
    }
    return 0;
}
