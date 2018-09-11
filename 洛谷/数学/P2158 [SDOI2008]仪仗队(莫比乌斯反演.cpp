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
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
const int maxn = 40005;
typedef long long ll;
int n,m,t;
bool is[maxn];
int cnt=0;
int pri[maxn],mu[maxn];
void init()
{
    mu[1]=1;
    for(int i =2;i<maxn;i++)
    {
        if(!is[i]){pri[cnt++]=i;mu[i]=-1;}
        for(int j =0;j<cnt&&pri[j]*i<maxn;j++)
        {
            is[i*pri[j]]=1;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            else mu[i*pri[j]]=-mu[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    init();
    if(n==1)cout<<0<<endl;
    else{
        ll ans=0;
        for(int i=1;i<=n-1;i++)
            {ans+=(mu[i]*((n-1)/i)*((n-1)/i));
           // cout<<ans<<endl;}
            }
        cout<<ans+2<<endl;
    }
    return 0;
}
