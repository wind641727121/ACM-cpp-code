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
int n[200005];
char a[200005];
void init()
{
    int j=0,k=-1;
    n[j]=k;
    while(j<m)
    {
        if(k==-1||a[k]==a[j])n[++j]=++k;
        else k=n[k];
    }
}
int main()
{
   // ios::sync_with_stdio(0);
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int ans=0;
            scanf("%d %s",&m,a);
            ans+=m;
            init();
            //cout<<ans<<endl;
            for(int i =1;i<=m;i++)
            {
                int j =i;
                while(n[j])
                {
                    ans=(ans+1)%10007;
                    j=n[j];
                }
            }
            printf("%d\n",ans%10007);
        }

    }
    return 0;
}
