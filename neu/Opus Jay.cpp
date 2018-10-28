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
string s[100005];
map<string,int> mp;
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
           cin>>n>>m>>k;
            int j=0;
            mp.clear();
            for(int i =0;i<n;i++)
            {
                cin>>s[j];
                int l=0;

                for(int k =0;k<m;k++)
                {
                    if(s[j][k]=='0') ++l;
                }
                //bug1(1213);
                if(l<=k&&(k-l)%2==0){ ++mp[s[j]];if(mp[s[j]]==1) ++j;}
               //  bug1(121);
            }
            int ans=0;
            for(int i =0;i<j;i++)
                ans=max(ans,mp[s[i]]);
            cout<<ans<<endl;

        }
    }
    return 0;
}
