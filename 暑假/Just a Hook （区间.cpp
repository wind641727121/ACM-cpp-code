#include <bits/stdc++.h>
using namespace std;
int n,m,t;
struct  node
{
    int p;
    int m;
}s [500000];
int inf=0x3f3f3f;
int made(int r,int b,int e)
{
    s[r].m=0;
    if(b==e) return s[r].p=1;
    else{
       int mid =(b+e)/2;
        s[r].p=made(r*2,b,mid)+made(r*2+1,mid+1,e);
        //cout<<s[r].p<<endl;
        return s[r].p;
    }
}
void p(int r)
{
    if(s[r].m!=0)
    {
        s[2*r].m=s[r].m;
        s[2*r+1].m= s[r].m;
        s[2*r].p=s[r].m;
        s[2*r+1].p=s[r].m;
        s[r].m=0;
    }
}
int q(int r,int b,int e,int c,int d)
{
    if(b>d||e<c)return 0;
    if(b>=c&&e<=d) {   return s[r].p;}
    if(b==e)return 0;
    int mid=(b+e)/2;
    p(r);
    return q(r*2,b,mid,c,d)+q(r*2+1,mid+1,e,c,d);
}
void ser(int r,int b,int e)
{
    if(e==b)return;
    else
    {
        if(s[r].m) p(r);
        int mid =(b+e)/2;
        ser(r*2,b,mid);
        ser(r*2+1,mid+1,e);
        s[r].p=s[r*2].p+s[r*2+1].p;
    }
}
void up(int r,int b,int e,int c,int d,int f)
{
    if(b>d||e<c)return ;
    if(b>=c&&e<=d) {s[r].p=f;s[r].m=f;return;}
    p(r);
    int mid =(b+e)/2;
    up(r*2,b,mid,c,d,f);
    up(r*2+1,mid+1,e,c,d,f);
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
            cin>>n>>m;
         //   for(int i =1;i<=n;i++) cin>>a[i];
            made(1,1,n);


            for(int i =0;i<m;i++)
            {
               //   cout<<"Case "<<++k<<": The total value of the hook is "<<q(1,1,n,1,n)<<"."<<endl;
                int c,d,e;
                cin>>c>>d>>e;
                up(1,1,n,c,d,e);

            }
            ser(1,1,n);
            cout<<"Case "<<++k<<": The total value of the hook is "<<q(1,1,n,1,n)<<"."<<endl;

        }
    }
    return 0;
}
