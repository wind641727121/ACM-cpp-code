#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int read()
{
    int s=0,w=1;
    char c;
    c= getchar();
    while(c>'9'||c<'0'){if(c=='-')w=-1;if(c==-1)exit(0);c=getchar();}
    while(c<='9'&&c>='0'){s=s*10+c-'0';c=getchar();}
    return s*w;
}
int n,l,p;
struct node
{
    int d,b;
    node(int x=0,int y =0){d=x,b=y;}
    friend bool operator >(node a,node b){return a.b<b.b;}
}a[10005];
bool cmp(node a,node b){return a.d>b.d;}
priority_queue<node,vector<node>,greater<node> >q;
int main(){
    ios::sync_with_stdio(0);
        while(cin>>n)
        {
           // q.clear();
            for(int i =0;i<n;i++) {cin>>a[i].d>>a[i].b;}//q.push(a[i]);}
           // cout<<q.top().d<<" "<<q.top().b<<endl;
            cin>>l>>p;
            sort(a,a+n,cmp);
          //  for(int i =0;i<n;i++) cout<<a[i].b<<" "<<a[i].d<<endl;
            int flag=0;
            for(int i =0,j=0;i<l;p--,i++)
            {
            //    cout<<i<<" "<<p<<endl;
                if(i>=l-a[j].d){q.push(a[j++]);}
                if(p==0)
                {
                    if(!q.empty()){p+=q.top().b;q.pop();flag++;}
                    else {flag=-1;break;}
                }
            }
            cout<<flag<<endl;
            while(!q.empty())q.pop();
        }
}
