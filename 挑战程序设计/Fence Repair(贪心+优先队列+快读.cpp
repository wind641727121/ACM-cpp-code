#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include <vector>
using namespace std;
int n,m,a;
typedef  long long ll;
//ll sum[20005];
priority_queue<ll,vector<ll>,greater<ll> > q;
bool cmp(int a,int b) {return a>b;}
inline int read()
{
    int w=0,s=1;
    char c;
    c=getchar();
    while(c>'9'||c<'0'){if(c=='-')s=-1;if(c==-1)exit(0);c=getchar();}
    while(c>='0'&&c<='9') {w=w*10+c-'0';c=getchar();}
    return w*s;
}
int main()
{
    //ios::sync_with_stdio(0);
    while(cin>>n)
    {
        for(int i =0;i<n;i++)
            {a =read();q.push(a);}
        ll ans=0;
        if(n==1) {cout<<a<<endl;continue;}
            while(q.size()>1)
            {
                ll x=q.top();q.pop();
                ll y = q.top();q.pop();
                ans+=x+y;
                q.push(x+y);
            }
        cout<<ans<<endl;

    }
    return 0;
}
