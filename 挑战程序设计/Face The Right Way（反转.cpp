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

typedef long long ll;
int n,m,t;
int a[5005];
int sum,f[5005];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n)
    {
        m=0;
        for(int i =1;i<=n;i++)
        {
            char c;
            cin>>c;
            if(c=='B')a[i]=0;
            else a[i]=1,m++;
        }
        if(m==n){cout<<1<<" "<<0<<endl;continue;}
        int ak=1,am=n;
        for(int k =1;k<=n;k++)
        {
            m=0;
            sum = 0;
            memset(f,0,sizeof f);
            for(int i = 1;i<=n-k+1;i++)
            {
                if((a[i]+sum)%2==0)
                {
                    ++m;
                    f[i]=1;
                }
                sum+=f[i];
                if(i+1>k) sum-=f[i+1-k];
            }
            for(int i =n-k+2;i<=n;i++)
            {
                if((a[i]+sum)%2==0) {m=0x3f3f3f;break;}
                sum-=f[i+1-k];
            }
            if(m<=am)
            {
                m==am?ak=min(ak,k):am=m,ak=k;
            }
        }
        cout<<ak<<" "<<am<<endl;
    }
    return 0;
}
