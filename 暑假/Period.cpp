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
int n;
string s,p;
int nex[1000005];
void makeNext()
{
    int q,k;
    int m = p.size();
    nex[0] = 0;

    for (q = 1,k = 0; q < m; ++q)
    {
        while(k > 0 && p[q] != p[k])
            k = nex[k-1];
        if (p[q] == p[k])
        {
            k++;
        }
        nex[q] = k;
    }

}
int kmp()
{
    int ans=0;
    int n,m;
    int i,q;
    n = s.size();
    m = p.size();
    makeNext();
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && p[q] != s[i])
            q = nex[q-1];
        if (p[q] == s[i])
        {
            q++;
        }
        if (q == m)
        {
            ++ans;
            q=nex[q-1];
        }
    }
    return ans;
}
int main()
{
    int t;
    ios::sync_with_stdio(0);
    int k =0;
    while(cin>>n&&n!=0)
    {
        cin>>p;
        //if(p==".") break;
        cout<<"Test case #"<<++k<<endl;
        makeNext();
         // bug(123);
        for(int i =1;i<p.size();i++)
            {
               // bug(123);
                if((i+1)%(i+1-nex[i])==0&&((i+1)/(1+i-nex[i]))>1)
                    cout<<i+1<<" "<<int((i+1)/(1+i-nex[i]))<<endl;
            }
            cout<<endl;
    }
    return 0;
}
