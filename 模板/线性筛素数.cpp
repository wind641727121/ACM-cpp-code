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
const int maxn = 1000000;
bool check[maxn];
int pri[maxn];
int cnt =0;
void prime()
{
    check[0]=check[1]=1;
    for(int i =2;i<maxn;i++)
    {
        if(!check[i])
            pri[cnt++]=i;
        for(int j =0;j<cnt&&i*pri[j]<maxn;j++)
        {
            check[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
}
