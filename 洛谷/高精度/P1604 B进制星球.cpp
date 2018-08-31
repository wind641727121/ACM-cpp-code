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
char ntc(int x)
{
    if(x>=0&&x<=9) return x+'0';
    else return x-10+'A';
}
int ctn(char x)
{
    if(x<='9'&&x>='0') return x-'0';
    else return x-'A'+10;
}
int main()
{
    ios::sync_with_stdio(0);
    int k;
    cin>>k;
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size()) swap(a,b);
    int i = a.size()-1,j=b.size()-1;
    int flag=0;
    while(i>=0&&j>=0)
    {
        int ha=ctn(a[i])+ctn(b[j]);
       // bug1(ha);
        if(ha<k)
        {
            b[j]=ntc(ha);
            j--;
            i--;
        }
        else
            {
               if(j==0)
               {
                   flag = 1;
                   b[j]=ntc(ha-k);
                   j--;
                   i--;
               }
               else
               {
                   b[j]=ntc(ha-k);
                   //bug1(b[j]);
                   ha = ctn(b[j-1]);
                   b[j-1]=ntc(ha+1);
                  // bug1(b[j-1]);
                   j--;
                   i--;
               }
            }
    }
    if(flag) cout<<flag;
    cout<<b<<endl;
    return 0;
}
