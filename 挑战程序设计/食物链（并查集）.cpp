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
int n,m,t,k;
int f[50005],r[50005];//根节点到i 0同类 1吃 2被吃
void init()
{
    for(int i =0;i<=n;i++) f[i]=i,r[i]=0;
}
int findd(int x)
{
   if(x==f[x])return x;
    int tem=f[x];
    f[x]=findd(f[x]);
    r[x]=(r[x]+r[tem])%3;
    return f[x];
}
void unio(int a,int b,int p)
{
    int x=findd(a),y=findd(b);
    if(x==y) return;
    f[y]=x;
    r[y]=((r[a]+p-1-r[b])%3+3)%3;
}
int main()
{
    //ios::sync_with_stdio(0);
    cin>>n>>k;
       int a,b,c;
       init();
       int ans=0;
       for(int i=0;i<k;i++)
       {
           c=read(),a=read(),b=read();
           if(a>n||b>n||a<1||b<1){++ans;continue;}
           if(findd(a)==findd(b))
           {
               if((3-r[a]+r[b])%3!=c-1){ans++;}
           }
           else unio(a,b,c);
       }
       cout<<ans<<endl;
    return 0;
}
