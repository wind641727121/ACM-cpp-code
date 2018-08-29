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
int n,m,t;
int tri[(int)5e5+12][28]={0};
int root=0;
int tot=0;
int sum[(int)5e5+12]={0};
void inser(char *s)
{
    int p = root;
    for(int i =0;s[i];i++)
    {
        int x = s[i]-'a';
        if(tri[p][x]==0)
        {
            tri[p][x]=++tot;
        }
       sum[tri[p][x]]++;
       p=tri[p][x];
    }
}
int cmp(char *s)
{
    int p=root;
    int len=strlen(s);
    //bug(len);
    for(int i =0;i<len;i++)
    {
        int x=s[i]-'a';
         if(i==len-1)
                {
                    // cout<<sum[tri[p][x]]<<" "<<i<<endl;
                    return sum[tri[p][x]];
                }
        p=tri[p][x];
        if(p==0)
            return 0;


    }
    return 0;
}
int main()
{
   // ios::sync_with_stdio(0);
    char s[20];
    while(1)
    {
        if((s[0]=getchar())=='\n')break;
        for(int i =1;;i++)
        {
            s[i]=getchar();
            if(s[i]=='\n')
            {
                s[i]='\0';
                break;
            }
        }
        inser(s);
    }
    while(cin>>s)
        cout<<cmp(s)<<endl;
//DELETE(root);
    return 0;
}
