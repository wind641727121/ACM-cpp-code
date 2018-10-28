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
string a[50];
int n[100],m,t;
void init(string a)
{
    int j=0,k=-1;
    n[j]=k;
    while(j<a.size())
    {
        if(k==-1||a[k]==a[j]){n[++j]=++k;}
        else k=n[k];
    }
}
int kmp(string a,string b)
{
    int i =0,j=0;
    init(a);
    while(i<b.size())
    {
        if(j==-1||b[i]==a[j])
        {
            ++i,++j;
            if(j==a.size()) return 1;
        }
        else j=n[j];
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    int k;
    while(cin>>k)
    {
        while(k--)
        {
            while(cin>>t){
                for(int i =0;i<t;i++)
                    cin>>a[i];
                string ans="-1",s;
                for(int i=0;i<a[0].size();i++)
                    for(int j =3;j+i<=a[0].size();j++)
                {
                    s=a[0].substr(i,j);
                   // bug3(i,j,s);
                    int flag=1;
                    for(int k=1;k<t;k++)
                    {

                        if(kmp(s,a[k])==0) {flag=0;break;}
                    }
                    if(flag) {
                        if(ans=="-1") ans=s;
                        else if(ans.size()<s.size()) ans=s;
                        else if(ans.size()==s.size()&&s<ans)ans=s;
                    }
                    else break;

                }
                if(ans=="-1"||ans.size()<3) cout<<"no significant commonalities"<<endl;
                else cout<<ans<<endl;
            }}
    }
    return 0;

}
