#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 0xfffffff
#define maxn 1002

int G[maxn][maxn];
int dist[maxn][maxn];
int m, n;
void Floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}
void Init()
{
    for(int i=0; i<=n; i++)
    {
        G[i][i] = 0;
        for(int j=0; j<i; j++)
            G[i][j] = G[j][i] = INF;
    }
}
    int gcd(int a,int b)
    {
        while(b^=a^=b^=a%=b);
        return a;
    }
int main()
{
     char a[100];
     scanf("%s",a);
     cout<<12<<a<<12<<endl;
    return 0;
}
