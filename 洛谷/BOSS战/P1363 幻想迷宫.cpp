#include<bits/stdc++.h>
using namespace std;
int n ,m;
char a[1505][1505];
bool vis[1505][1505];
bool vis2[4505][4505];
int flag=0,ha;
void dfs1(int x,int y,int fx,int fy)//
{
    if(flag)return;
    if(fabs(fx)>2*n||fabs(fy)>2*m)return;
    for(int i=-1;i<=1&&!flag;i++)
        for(int j=-1;j<=1&&!flag;j++)
    {
      if(i==0&&j==0)continue;
       if(i==0||j==0)
        {
            int xx=((fx+i)%n+n)%n,yy=((fy+j)%m+m)%m;
            if((xx==fx+i&&yy==fy+j)&&vis[xx][yy]==1)continue;
            else if(vis[xx][yy]==1){flag=1;return;}
            if(a[xx][yy]=='#') continue;
            if(xx==fx+j&&yy==fy+j)vis[xx][yy]=1;
            if(vis2[fx+i+1501][fy+j+1501])continue;
            vis2[fx+i+1501][fy+j+1501]=1;
      //     cout<<xx<<" "<<yy<<" "<<fx+i<<" "<<fy+j<<endl;
            dfs1(xx,yy,fx+i,fy+j);
             if(xx==fx+j&&yy==fy+j)vis[xx][yy]=0;
            vis2[fx+i+1501][fy+j+1501]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>m){
    int x,y;
    flag = 0;
    memset(vis,0,sizeof vis);
    memset(vis2,0,sizeof vis2);
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
           {
                cin>>a[i][j];
                if(a[i][j]=='S')x=i,y=j;
           }
    vis[x][y]=1;
  //  cout<<23123123<<" "<<x<<" "<<y<<endl;
    dfs1(x,y,x,y);
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
    return 0;
}
