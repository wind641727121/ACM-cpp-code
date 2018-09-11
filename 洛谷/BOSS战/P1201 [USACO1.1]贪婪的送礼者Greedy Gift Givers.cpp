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
int n,t;
map<string,int>m;
string a[15];
int q[15];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i =0;i<n;i++)
        {
            cin>>a[i];
            m.insert(make_pair(a[i],i));
        }
    int ha,num;
    string s;
    for(int i =0;i<n;i++)
        {
            cin>>s>>ha>>num;
            if(num==0) continue;
            int x = ha/num;
            q[m[s]]-=x*num;
            // bug1(12);
            for(int i =0;i<num;i++)
            {
                cin>>s;
                q[m[s]]+=(ha/num);
            }
            // bug1(123);
        }
       for(int i =0;i<n;i++)
        {
            cout<<a[i]<<" "<<q[m[a[i]]]<<endl;
        }
    return 0;
}
