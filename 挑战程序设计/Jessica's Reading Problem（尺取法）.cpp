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
typedef long long ll;
int n,m,t;
set<int> s;
int a[1000005];
map<int,int>ha;
inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')w = -1;if(ch==-1) exit(0); ch = getchar();} //快读小细节，getchar()==-1时直接exit(0);
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
int main()
{
  //  ios::sync_with_stdio(0);
    //cout<<ha[10]<<" "<<ha[11]<<endl;
    while(n=read())
    {
        s.clear();
        ha.clear();
        for(int i =0;i<n;i++)
             a[i]=read(),s.insert(a[i]);
        int num =s.size();
       // s.clear();
        int i=0,j=0,ans=0x3f3f3f,siz=0;
        while(siz==0||i<j){
                //flag=1;
        for(;j<n&&siz!=num;j++)
        {
            if(ha[a[j]]==0) ++siz;
            ++ha[a[j]];
            //s.insert(a[j]);
            if(siz==num)break;
        }
        if(j==n) break;
        ans=min(ans,j-i+1);
      //  bug3(i,j,ha[a[i]]);
        if(ha[a[i]]==1){siz--;++j;}
        ha[a[i]]--;
        ++i;
        }
        if(siz==num)  ans=min(ans,j-i);
        cout<<ans<<endl;
    }
    return 0;
}
