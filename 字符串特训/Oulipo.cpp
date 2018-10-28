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
int m,t;
string a,b;
int n[10005];
void init()
{
    int j=0,k=-1;
    n[0]=-1;
    while(j<a.size())
    {
        if(k==-1||a[j]==a[k])
        {
            //if(n[++j]==n[++k]) n[j]=n[k];
           //else n[j]=k;
           n[++j]=++k;
        }
        else k=n[k];
    }
}
int kmp()
{
    int i =0,j=0,ans=0;
    while(i<b.size())
    {
        if(j==-1||b[i]==a[j])
        {
             ++i,++j;
            if(j==a.size()){++ans;j=n[j];}

        }
        else j =n[j];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--){
        cin>>a>>b;
        init();
        cout<<kmp()<<endl;
    }
    }
    return 0;
}
