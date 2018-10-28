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
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
typedef long long ll;
int n,m,t[400005];
void init(int r,int l,int r)
{
    if(l==r) t[r]=a[l];
    int mid =(l+r)>>1;
    init(r*2,l,mid);
    init(r*2+1,mid+1,r);
    t[r]=min(t[r*2],t[r*2+1]);

}
int a[100000];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i =0;i<n;i++) cin>>a[i];
    return 0;
}
