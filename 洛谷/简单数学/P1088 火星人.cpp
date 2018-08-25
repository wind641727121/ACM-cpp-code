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
int n,m,t;
int a[10005];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m)
    {
        for(int i =0;i<n;i++) cin>>a[i];
        while(m--) next_permutation(a,a+n);
        for(int i =0;i<n;i++)
        {
            cout<<a[i];
            if(i!=n-1)cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}
