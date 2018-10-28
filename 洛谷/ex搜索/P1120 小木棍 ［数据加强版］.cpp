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
vector<int> a;
int main()
{
    ios::sync_with_stdio(0);
     cin>>t;
     n=0;
     int ans=0,maxx=-1;
     for(int i =0;i<t;i++){
        cin>>m;
        if(m<=50) maxx=max(m,maxx),a.push_back(m),ans+=m;
     }
    for(int i=maxx;i<=ans;i++)
    if(ans%i==0) {cout<<i<<endl;return 0;}
    return 0;
}
