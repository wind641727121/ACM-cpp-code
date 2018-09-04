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
int main(){
    std::ios::sync_with_stdio(0);
    freopen("pi.txt","r",stdin);
  //  freopen("ha.out","w",stdout);
    ll n=0;
    ll a[15]={0};
    char c;
    while(cin>>c)
        ++n,++a[c-'0'];
    cout<<"共小数点后 "<<n<<" 位："<<endl;
    for(int i=0;i<10;i++)
        cout<<"数字 "<<i<<"出现： "<<a[i]<<"次"<<endl;
    getchar();
    return 0;

}
