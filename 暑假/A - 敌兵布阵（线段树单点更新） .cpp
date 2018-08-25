#include <bits/stdc++.h>
using namespace std;
int n,m,t;
struct  node
{
    int p;
}s [450000];
int a[50010];
int inf=0x3f3f3f;
int made(int r,int b,int e)
{
    if(b==e) return s[r].p=a[b];
    else{
       int mid =(b+e)/2;
        s[r].p=made(r*2,b,mid)+made(r*2+1,mid+1,e);
        //cout<<s[r].p<<endl;
        return s[r].p;
    }
}
int q(int r,int b,int e,int c,int d)
{
   // cout<<r<<" "<<b<<" "<<e<<" "<<s[r].p<<endl;
    if(b>d||e<c)return 0;
    if(b>=c&&e<=d) {   return s[r].p;}
    if(b==e)return 0;
    int mid=(b+e)/2;
    return q(r*2,b,mid,c,d)+q(r*2+1,mid+1,e,c,d);
}
void A(int r,int b,int e,int c,int d)
{
    if(b==e&&b==c) {s[r].p=s[r].p+d;  return;}
    else if(b==e) return ;
    int mid =(b+e)/2;
    if(c<=mid)  A(r*2,b,mid,c,d);
    else A(r*2+1,mid+1,e,c,d);
    s[r].p=s[r*2].p+s[r*2+1].p;
}
int main()
{
    ios::sync_with_stdio(0);
    while (cin>>t)
    {
        int k =0;
        while(t--)
        {
            memset(s,0,sizeof s);
            cout<<"Case "<<++k<<":"<<endl;
            cin>>n;
            for(int i =1;i<=n;i++) cin>>a[i];
            made(1,1,n);
            string a;
            while(cin>>a)
            {
                if(a=="End")break;
                else if(a=="Query")
                {
                    int c,d;
                    cin>>c>>d;
                    cout<<q(1,1,n,c,d)<<endl;
                }
                else if(a=="Add")
                {
                    int c,d;
                    cin>>c>>d;
                    A(1,1,n,c,d);
                }
                else{
                    int c,d;
                    cin>>c>>d;
                    A(1,1,n,c,-d);
                }
            }
        }
    }
    return 0;
}
