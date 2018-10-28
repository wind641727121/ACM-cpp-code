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
int main()
{
    while(cin>>t)
    {
        while(t--)
        {
            double a=0,b=0,ans=0;
            scanf("%lf %lf",&a,&b);
            if(a==b&&(a==0||a==1)) {cout<<"1.000"<<endl;continue;}
            ans=(1-a)*(1-b);
            double tmp1=1,last=1;
            int l = 1;
            double n =a*b;
            while(tmp1>=0.0001)
            {
                double m=1;
                for(int i =0;i<l;i++)
                    tmp1*=n,m*=(1-a)*(1-b)*(1-a)*(1-b);
                ans+=tmp1*m;
                last=tmp1;
                l*=2;
            }
            printf("%.3f\n",ans);
        }
    }
    return 0;
}
