#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<queue>
using namespace std;
typedef long long ll;
int n,m,t;
char a[5][5];
void r(int i)
{
    if(i==1)
    {
        int t =a[2][1];
        a[2][1]=a[2][2];
        a[2][2]=a[1][2];
        a[1][2]=a[1][1];
        a[1][1]=t;
    }
    else if(i==2)
    {
        int t =a[2][2];
        a[2][2]=a[2][3];
        a[2][3]=a[1][3];
        a[1][3]=a[1][2];
        a[1][2]=t;
    }
    else if(i==3)
    {
        int t =a[3][1];
        a[3][1]=a[3][2];
        a[3][2]=a[2][2];
        a[2][2]=a[2][1];
        a[2][1]=t;
    }
    else if(i==4)
    {
        int t =a[3][2];
        a[3][2]=a[3][3];
        a[3][3]=a[2][3];
        a[2][3]=a[2][2];
        a[2][2]=t;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            for(int i =1;i<=3;i++)
                for(int j =1;j<=3;j++)cin>>a[i][j];
            for(int i =0;i<n;i++)
            {
                int a;char b;
                cin>>a>>b;
                if(b=='C') r(a);
                else r(a),r(a),r(a);
            }
            for(int i =1;i<=3;i++)
                {for(int j =1;j<=3;j++)cout<<a[i][j];cout<<endl;}
        }
    }
    return 0;
}
