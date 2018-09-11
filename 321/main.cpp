#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pb push_back
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll MAXN=2e3+10;
struct node{
    int id,cost;
};
node match[MAXN][MAXN];
int use[MAXN];
int deg[2*MAXN];
vector<int> e[MAXN];
int n,m,r,l;
int dfs(int now){
    use[now]=1;
    for (int i=0;i<e[now].size();i++){
        if (use[e[now][i]])
            continue;
        if ((r-deg[e[now][i]])>=(l-deg[now])){
            deg[e[now][i]]+=l-deg[now];
            match[e[now][i]][now].cost=l-deg[now];
            deg[now]=l;
            return 1;
        }
        for (int j=1;j<=(n+m);j++){
            node temp=match[e[now][i]][j];
            if (use[temp.id])
                continue;
            deg[temp.id]-=temp.cost;
            deg[e[now][i]]-=temp.cost;
            if (!dfs(temp.id))
            {
                int t1=l-deg[temp.id];
                match[e[now][i]][j].cost=t1;
                deg[temp.id]=l;
                deg[e[now][i]]+=t1;
            }
            else  match[e[now][i]][j].cost=0;
            if ((r-deg[e[now][i]])>=(l-deg[now]))
                break;
        }
        if ((r-deg[e[now][i]])>=(l-deg[now])){
            deg[e[now][i]]+=l-deg[now];
            match[e[now][i]][now].cost=l-deg[now];
            deg[now]=l;
            return 1;
        }

    }
    return 0;
}
int main(){
    int i,j,k,t1,t2,t3,key;
    std::ios::sync_with_stdio(0);
    int tt=1;
    while (cin>>n>>m>>k){
        memset(deg,0,sizeof(deg));
        cin>>l>>r;
        r--;
        memset(match,0,sizeof(match));
        for(i=0;i<k;i++)
            e[i].clear();
        for (i=0;i<k;i++){
            cin>>t1>>t2;
            t2+=n;
            deg[t1]++;
            deg[t2]++;
            e[t1].pb(t2);
            e[t2].pb(t1);
        }
        key=1;
        for (i=1;i<=n+m;i++){
            if (deg[i]>r){
                key=0;
                break;
            }
            if (deg[i]<l){
                memset(use,0,sizeof(use));
                if (!dfs(i)){
                    key=0;
                    break;
                }
            }
        }
        if (key)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}
