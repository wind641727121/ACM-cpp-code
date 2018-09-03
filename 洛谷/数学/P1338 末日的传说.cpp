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
int n,i;
int a[50005],b,c;
long long ans;
int main()
{
    ll m;
   while( cin>>n>>m){
    for(int i=0;i<n;i++) a[i]=i;
      while(m&&next_permutation(a,a+n))
      {
          m--;
      }
        for(int i =0;i<n;i++)
        {
            cout<<(int)a[i]+1;
            if(i!=n-1)cout<<" ";
            else cout<<endl;
        }
    }
    return 0;

}
