#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000;
int sum[MAXN];
int a[MAXN];
int main(){
    std::ios::sync_with_stdio(0);
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));
    a[53]=a[23]=a[31]=a[71]=a[17]=a[37]=a[73]=a[137]=a[173]=a[317]=a[113]=a[131]=a[311]=a[13]=1;
    for (int i=1;i<1000;i++)
        if (a[i])
            sum[i]=max(sum[i-1],a[i]);
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        if (s.size()>3)
            cout<<sum[999]<<'\n';
        else {
            int t1=s.size()-1;
            int t2=0;
            while (t1){
                t2*=10;
                t2+=s[t1--]-'0';
            }
            cout<<sum[t2]<<'\n';
        }
    }
}
