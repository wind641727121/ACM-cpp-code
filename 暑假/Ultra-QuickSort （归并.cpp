#include<iostream>
using namespace std;
long long n,a[500005],c[500005],ans;
void sorts(int l,int r)
{
    if(l==r) return ;
    int mid =(l+r)/2;
    sorts(l,mid);sorts(mid+1,r);
    int i = l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) c[k++]=a[i++];
        else{
            c[k++]=a[j++];
            ans+=(mid-i+1);
        }
    }
    while(i<=mid) c[k++]=a[i++];
    while(j<=r) c[k++]=a[j++];
    for(int i =l;i<=r;i++)
        a[i]=c[i];
}
int main()
{
   ios::sync_with_stdio(0);
    while(cin>>n)
    {

            if(n==0)break;
            for(int i=0;i<n;i++) cin>>a[i];
            ans=0;
            sorts(0,n-1);
            cout<<ans<<endl;

    }
    return 0;
}
