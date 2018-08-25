#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,t;
int prime[1000][20];
int cnt[1000];
int maxn;
void in()
{
    memset(cnt,0,sizeof cnt);
    for(int i=2;i<maxn;i++)
    {
        if(cnt[i]) continue;
        prime[i][0]=i;
        cnt[i];
        for(int j =2*i;j<maxn;j+=i)
            prime[j][cnt[j]++]=i;
    }
}
