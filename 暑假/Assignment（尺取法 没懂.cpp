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
ll n,m,t,k;
ll a[100005];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>k;
            ll ans=0;
            for(int i=0;i<n;i++)
                cin>>a[i];
            ll j=0,i=0;
            ll maxx=a[0],minn=a[0];
            while(i<=j&&j<n){
                maxx=max(maxx,a[j]);
                minn=min(minn,a[j]);
                if(maxx-minn>=k)
                {
                    ans+=(j-i);
                     if(maxx==a[i]||minn==a[i])
                    {
                        maxx=-1,minn=0x3f3f3f3f;
                        for(int x=i+1;x<=j-1;x++)
                           {
                            maxx=max(maxx,a[x]);
                            minn=min(minn,a[x]);}
                    }
                    i++;
                }
                else{
                    j++;
                 }

                    }
                   		while(i < n)
                    {
                        ans += j - i;
                        i++;
                    }
            cout<<ans<<endl;
        }
    }
    return 0;
}
