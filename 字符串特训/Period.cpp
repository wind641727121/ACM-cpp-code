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
int n[1000005];
typedef long long ll;
int t;
string a;
void init()
{
    int j=0,k=-1;
    n[0]=-1;
    while(j<a.size())
    {
        if(k==-1||a[j]==a[k])
            n[++j]=++k;
        else k=n[k];
    }
}
int main()
{
    int k =0;
    ios::sync_with_stdio(0);
    while(cin>>t&&t)
    {
        cin>>a;
        cout<<"Test case #"<<++k<<endl;
        init();
        for(int i =1;i<a.size();i++)
        {
            int l =i+1-n[i+1];
            if((i+1)%l==0&&(i+1)!=l)
            {
                cout<<i+1<<" "<<(i+1)/l<<endl;
            }
        }
        cout<<endl;

    }
    return 0;
}
