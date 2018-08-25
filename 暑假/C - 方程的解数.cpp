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
typedef long long ll;
int poww(int a, int b) {
    int ans = 1, base = a;
    while (b != 0) {
        if (b & 1 != 0)
            ans *= base;
            base *= base;
            b >>= 1;
    }
    return ans;
}
int n,m,t;
int k[10],p[10],f[4000000];
int main()
{
    ios::sync_with_stdio(0);
    //cout<<poww(2,5);
        while(cin>>n>>m)
        {
            memset(k,0,sizeof k);
            memset(p,0,sizeof p);
            for(int i =0;i<n;i++) cin>>k[i]>>p[i];
            int t =0;
            if(n==6){
            for(int i =1;i<=m;i++)
                for(int j =1;j<=m;j++)
                    for(int l =1;l<=m;l++)
                        f[t++]=k[0]*poww(i,p[0])+k[1]*poww(j,p[1])+k[2]*poww(l,p[2]);
            sort(f,f+t);
           // cout<<123<<endl;

            int ans=0;
             for(int i =1;i<=m;i++)
                for(int j =1;j<=m;j++)
                    for(int l =1;l<=m;l++)
                    {
                        int h =k[3]*poww(i,p[3])+k[4]*poww(j,p[4])+k[5]*poww(l,p[5]);
                        h=-h;
                        ans+=upper_bound(f,f+t,h)-lower_bound(f,f+t,h);
                      //  cout<<ans<<endl;
                    }
                    cout<<ans<<endl;}
                    else if(n==5)
                    {
                         for(int i =1;i<=m;i++)
                for(int j =1;j<=m;j++)
                    for(int l =1;l<=m;l++)
                        f[t++]=k[0]*poww(i,p[0])+k[1]*poww(j,p[1])+k[2]*poww(l,p[2]);
            sort(f,f+t);
           // cout<<123<<endl;

            int ans=0;
             for(int i =1;i<=m;i++)
                for(int j =1;j<=m;j++)
                    {
                        int h =k[3]*poww(i,p[3])+k[4]*poww(j,p[4]);
                        h=-h;
                        ans+=upper_bound(f,f+t,h)-lower_bound(f,f+t,h);
                      //  cout<<ans<<endl;
                    }
                    cout<<ans<<endl;
                    }
                     else if(n==4)
                    {
                         for(int i =1;i<=m;i++)
                for(int j =1;j<=m;j++)
                    for(int l =1;l<=m;l++)
                        f[t++]=k[0]*poww(i,p[0])+k[1]*poww(j,p[1])+k[2]*poww(l,p[2]);
            sort(f,f+t);
            int ans=0;
             for(int i =1;i<=m;i++)
                    {
                        int h =k[3]*poww(i,p[3]);
                        h=-h;
                        ans+=upper_bound(f,f+t,h)-lower_bound(f,f+t,h);
                      //  cout<<ans<<endl;
                    }
                    cout<<ans<<endl;
                    }
                     else if(n==3)
                    {
                        int ans=0;
                        for(int i =1;i<=m;i++)
                        for(int j =1;j<=m;j++)
                        for(int l =1;l<=m;l++)
                        if((k[0]*poww(i,p[0])+k[1]*poww(j,p[1])+k[2]*poww(l,p[2]))==0) ++ans;
                        cout<<ans<<endl;

                    }
                     else if(n==2)
                    {
                        ll ans=0;
                         for(int i =1;i<=m;i++)
                        for(int j =1;j<=m;j++)
                      if((k[0]*poww(i,p[0])+k[1]*poww(j,p[1]))==0) ++ans;
                        cout<<ans<<endl;

                    }
                      else if(n==1)
                    {
                        ll ans=0;
                         for(int i =1;i<=m;i++)
                        if((k[0]*poww(i,p[0]))==0) ++ans;
                        cout<<ans<<endl;

                    }


        }
    return 0;
}
