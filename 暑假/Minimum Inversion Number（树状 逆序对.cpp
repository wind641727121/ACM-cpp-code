#include<iostream>
#include<cstring>
#include<algorithm>
using  namespace std;
typedef  long long ll;
int bit[10000],n,a[10000];
int lowbit(int i){return i&(-i);}
ll q(int i)
{
    ll ans=0;
    while(i>0)
    {
        ans+=bit[i];
        i-=lowbit(i);
    }
    return ans;
}
int add(int i)
{
    while(i<=n)
    {
        bit[i]++;
        i+=lowbit(i);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n)
    {
        ll ans=0;
        memset(bit,0,sizeof bit);
        for(int i =1;i<=n;i++)
        {
            cin>>a[i];
            ++a[i];
            add(a[i]);
            ans+=(i-q(a[i]));
           // cout<<i<<" "<<q[n]<<endl;

        }
        ll mm=ans;
        for(int i =1;i<=n;i++)
        {
            ans+=(n-a[i]-a[i]+1);
            mm=min(ans,mm);
        }
        cout<<mm<<endl;
    }
    return 0;
}
