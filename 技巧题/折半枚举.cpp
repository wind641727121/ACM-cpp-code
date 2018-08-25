//https://blog.csdn.net/qq_37636528/article/details/62237914
#include<iostream>
#include<algorithm>
using namespace std;
int a[4005],b[4005],c[4005],d[4005],f[4005*4005];
int main()
{
    int n;
    ios::sync_with_stdio(0);
    while(cin>>n)
    {
        for(int i =0;i<n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
        int k=0,ans=0;
        for(int i =0;i<n;i++)
            for(int j =0;j<n;j++)
                f[k++]=c[i]+d[j];
        sort(f,f+k);
        for(int i =0;i<n;i++)
            for(int j =0;j<n;j++)
        {
            int ha=-(a[i]+b[j]);
            ans+=upper_bound(f,f+k,ha)-lower_bound(f,f+k,ha);
        }
        cout<<ans<<endl;
    }
}
