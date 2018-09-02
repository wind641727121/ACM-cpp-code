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
ll n,m,t,k;
ll poww(ll a,ll b)
{
    ll ans=1,base=a;
    while(b!=0)
    {
        if(b&1!=0)
            ans=(ans*base);
        base =(base*base);
        b>>=1;
    }
    return ans;
}
priority_queue <int,vector<int>,greater<int> >a;
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>k)
    {

        ll s = 1;
        int m = 1;
        while(n)
        {
            if(n%2==1) a.push(s);
            n=n/2;
//            b.push_back(s);
            //bug2(m,s);
            //m=m*2;
            s=s*2;

        }
       // b.push_back(s);
        if(a.size()<=k) {cout<<0<<endl;continue;}
       // bug1(a.size());
        ll ans=0;
      while(a.size()>k)
        {
          //  bug2(a.top(),b[a.top()]);
            ans+=a.top();
            ll ha =a.top()*2;
            a.pop();
            while(!a.empty()&&a.top()==ha)
            {
                a.pop();
                ha=ha*2;
            }
            a.push(ha);
        }
        cout<<ans<<endl;
    }
    return 0;
}
