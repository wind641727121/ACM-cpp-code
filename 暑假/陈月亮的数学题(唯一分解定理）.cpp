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
#define bug() cout<<123213<<endl
//所以，我们可以从1+2+3+…+n=(1+n)n/2。
//1^3+2^3+3^3+…+n^3=((1+n)n/2)^2
//https://blog.csdn.net/liangzhaoyang1/article/details/53509295
typedef long long ll;
const int maxn=65536;
int prime[maxn+10];
ll ans =0;
int t,n;
vector<int>pricount;
int len=0;
void init() //素数打表
{
    for(int i=2; i<=maxn; i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1; j<=prime[0] && prime[j]<=maxn/i; j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
void get_divisor(int n)
{
    for(int i=1; i<=prime[0] && prime[i] *prime[i]<=n; i++)
    {
        int cnt=0;
        while(n % prime[i]==0)
        {
            cnt++;
            n/=prime[i];
        }
        if(cnt)
            pricount.push_back(cnt);
    }
    if(n>1)
        pricount.push_back(1);
}
int main()
{
    init();
    cin>>t;
   // for(int i =0;i<=100;i++) cout<<prime[i]<<endl;
    while(t--)
    {
        pricount.clear();
        ans=1;
        cin>>n;
        get_divisor(n);
        len=pricount.size();
        //for(vector<int>::iterator it= pricount.begin();it!=pricount.end();it++)
        //cout<<*it<<endl;
        ll tmp;
        for(int i=0; i<len; i++)
        {
            tmp=(pricount[i]+1) *(pricount[i]+2)/2;
            ans*=tmp*tmp;
        }
        cout<<ans<<endl;

    }
    return 0;
}
