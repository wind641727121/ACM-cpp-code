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
int  m,t;
string a,b;
int n[5005005];
int init(string a)
{
    int j=0,k=-1;
    n[j]=k;
    while(j<a.size())
    {
        if(k==-1||a[j]==a[k])n[++j]=++k;
        else k=n[k];
    }
    return n[a.size()];
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>a>>b)
    {
        int minn =min(a.size(),b.size());//,j=b.size()-1;
        a+=b;
        minn=min(minn,init(a));
        if(minn==0) cout<<0<<endl;
        else
        {
            for(int i =0;i<minn;i++)
                cout<<a[i];
            cout<<" "<<minn<<endl;
        }
    }
    return 0;
}
