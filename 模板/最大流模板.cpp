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
#define bug(g) cout<<g<<endl
typedef long long ll;
//最大流板子
//用#define type xxx替代流的类型(int, double, long long)
//极其关键：边数开两倍
int n;
int s, t;
struct Edge {
    int from, to, next;
    type cap, flow;
    void get (int u, int a, int b, type c, type d) {
    from = u; to = a; next = b; cap = c; flow = d;
    }
}edge[maxm];
int tol;
int head[maxn];
int gap[maxn], dep[maxn], pre[maxn], cur[maxn];
void init () {
    tol = 0;
    memset (head, -1, sizeof head);
}
void add_edge (int u, int v, type w, type rw=0) {
    //cout << u << " " << v << " " << w << endl;
    edge[tol].get(u, v,head[u],w,0);head[u]=tol++;
    edge[tol].get(v, u,head[v],rw,0);head[v]=tol++;
}
type sap (int start, int end, int N) {
    memset (gap, 0, sizeof gap);
    memset (dep, 0, sizeof dep);
    memcpy (cur, head, sizeof head);
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    type ans = 0;
    while (dep[start] < N) {
        if (u == end) {
            type Min = INF;
            for (int i = pre[u]; i != -1; i = pre[edge[i^1].to])
                if (Min > edge[i].cap - edge[i].flow)
                   Min = edge[i].cap-edge[i].flow;
            for (int i = pre[u]; i != -1; i = pre[edge[i^1].to]) {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v]+1 == dep[u]) {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if (flag) {
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].next)
            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min) {
	              Min = dep[edge[i].to];
	              cur[u] = i;
	         }
        gap[dep[u]]--;
        if (!gap[dep[u]]) return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if (u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}
