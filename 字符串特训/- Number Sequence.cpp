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
typedef unsigned long long ull;
int n,m,t;
int a[1000005],b[100005];
int nex[100005];
void init()
{
    int j =0,k=-1;
    nex[0]=-1;
    while(j<m-1)
    {
        if(k==-1||b[k]==b[j])
        {
            if(b[++j]==b[++k])
            nex[j]=nex[k];
            else nex[j]=k;
        }
        else k=nex[k];
    }
}
int kmp()
{
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(j==-1||a[i]==b[j]) ++i,++j;
        else
            j=nex[j];

    }
    if(j==m) return i-m+1;
    else return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>m;
            for(int i =0;i<n;i++)
                cin>>a[i];
            for(int i =0;i<m;i++)
                cin>>b[i];
        init();
        cout<<kmp()<<endl;
    }
    }
    return 0;
}
