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

typedef long long ll;
int m;
string ha[]= {"A","2","3","4","5","6", "7", "8", "9","10","J","Q","K"};
string ca[]= {"10","2","3","4","5","6", "7", "8", "9","A","J","K","Q"};
map<string,int>p[4],t;
string a;
int i,j,k;
int n[5];
inline int p1(int flag,vector<string> &tmp,vector<int>&num)// 1หตปั 0 รป
{
    if(flag)
    {
        if(p[0][a])
        {
            --p[0][a],tmp.push_back(a),num.push_back(1);
            --n[1];
            return 0;
        }
        else
        {
            for(i=0; i<13; i++)
                if(p[0][ca[i]])
                {
                    --p[0][ca[i]];
                    tmp.push_back(ca[i]);
                    num.push_back(1);
                    --n[1];
                    return 1;
                }
        }
    }
    if(k%4==3&&p[0][ha[(k+1)%13]]==0)
    {
        return 1;
    }
//     if(k%4==3)
//       {
//            if(num.size()==1&&(num[0]+p[0][tmp[0]])>4) return 1;
//            if(num.size()==2&&(num[1]+num[2]+p[0][tmp[0]])
//       }
    int sum=0;
    for( i=0; i<tmp.size(); i++)
    {
        sum+=num[i];

    }
    if(sum+p[0][a]>4)
    {
        return 1;
    }
    return 0;
}
inline int p2(int flag,vector<string> &tmp,vector<int>&num)
{
    if(flag)
    {
        if(p[1][a])
        {
            tmp.push_back(a),num.push_back(p[1][a]);
            n[2]-=p[1][a];
            p[1][a]=0;
            return 0;
        }
        else
        {
            for(i=0; i<13; i++)
                if(p[1][ca[i]])
                {
                    --p[1][ca[i]];
                    tmp.push_back(ca[i]);
                    num.push_back(1);
                    --n[2];
                    return 1;
                }
        }
    }
    if(k%4==0&&p[1][ha[(k+1)%13]]==0)
    {
        return 1;
    }
    return 0;
}
inline int p3(int flag,vector<string> &tmp,vector<int>&num)
{
    if(flag)
    {
        if(p[2][a])
        {
            tmp.push_back(a),num.push_back(p[2][a]);
            n[3]-=p[2][a];
            p[2][a]=0;
            return 0;
        }
        else
        {
            string b;
            int minn=10;
            for(i=0; i<13; i++)
                if(p[2][ca[i]]>=1&&p[2][ca[i]]<minn)
                {
                    b=ca[i],minn=p[2][ca[i]];
                }
            tmp.push_back(b),num.push_back(minn),p[2][b]=0,n[3]-=minn;
            return 1;
        }
    }
    // cout<<123<<endl;
    if(p[2][a]==4)
    {
        return 1;
    }
    // cout<<23<<endl;
    return 0;
}
inline int p4(int flag,vector<string> &tmp,vector<int>&num)
{
    if(flag)
    {
        if(p[3][a]>=3)
        {
            tmp.push_back(a),num.push_back(p[3][a]);
            n[4]-=p[3][a];
            p[3][a]=0;
            return 0;
        }
        else
        {
            if(p[3][a])
            {
                tmp.push_back(a),num.push_back(p[3][a]),n[4]-=p[3][a],p[3][a]=0;
            }
            if(n[4]==0)
                return 0;
            for(i=0; i<13; i++)
                if(p[3][ca[i]])
                {
                    --p[3][ca[i]];
                    tmp.push_back(ca[i]);
                    num.push_back(1);
                    --n[4];
                    return 1;
                }
            return 0;
        }
    }
    // cout<<123<<endl;
    if(n[k%4+1] ==0)
    {
        return 1;
    }
    // cout<<23<<endl;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>a)
    {
        p[0].clear();
        p[1].clear();
        p[2].clear();
        p[3].clear();
        t.clear();
        ++p[0][a];
        for(i =1; i<13; ++i)
            cin>>a,++p[0][a];
        for( i =1; i<=3; ++i)
            for(j=0; j<13; ++j)
                cin>>a,++p[i][a];
        k=-1;
        n[1]=n[2]=n[3]=n[4]=13;
        while(n[1]&&n[2]&&n[3]&&n[4])
        {
            vector<string> tmp;
            vector<int>num;
            int flag=0;
//            for(int i=0;i<4;i++)
//            {
//                cout<<"P"<<i+1<<":  ";
//                for(int k =0;k<13;k++)
//                for(int j=p[i][ha[k]];j>0;j--)cout<<ha[k]<<" ";
//            cout<<endl;
            //        }
            a=ha[(++k)%13];
            switch(k%4)
            {
            case 0:
                flag=p1(1,tmp,num);
                break;
            case 1:
                flag=p2(1,tmp,num);
                break;
            case 2:
                flag=p3(1,tmp,num);
                break;
            case 3:
                flag=p4(1,tmp,num);
                break;
            }
            for(i=0; i<tmp.size(); i++)
                t[tmp[i]]+=num[i];
            //     cout<<k%4+1<<endl;
//            cout<<"beg:  ";
//           for(int k =0;k<13;k++)
//                for(int j=t[ha[k]];j>0;j--)cout<<ha[k]<<" ";
//            cout<<endl;
            //   cout<<1<<endl;
            if(k%4==0||k%4==3)
            {
                if(k%4!=0&&p1(0,tmp,num))
                {
                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[0][ha[i]]+=t[ha[i]],n[1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }

                if(k%4!=1&&p2(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[1][ha[i]]+=t[ha[i]],n[2]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
                //   cout<<3<<endl;
                if(k%4!=2&&p3(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[2][ha[i]]+=t[ha[i]],n[3]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
                //    cout<<4<<endl;
                if(k%4!=3&&p4(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[3][ha[i]]+=t[ha[i]],n[4]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
            }
            else  if(k%4==1)
            {
                if(k%4!=2&&p3(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[2][ha[i]]+=t[ha[i]],n[3]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
                //    cout<<4<<endl;
                if(k%4!=3&&p4(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[3][ha[i]]+=t[ha[i]],n[4]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }

                if(k%4!=0&&p1(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[0][ha[i]]+=t[ha[i]],n[1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
            }
            else   if(k%4==2)
            {
                if(k%4!=3&&p4(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[3][ha[i]]+=t[ha[i]],n[4]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
                if(k%4!=0&&p1(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[0][ha[i]]+=t[ha[i]],n[1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }

                if(k%4!=1&&p2(0,tmp,num))
                {

                    if(flag)
                    {
                        for(i=0; i<13; i++)
                            p[k%4][ha[i]]+=t[ha[i]],n[k%4+1]+=t[ha[i]],t[ha[i]]=0;
                    }
                    else
                    {
                        for(i=0; i<13; i++)
                            p[1][ha[i]]+=t[ha[i]],n[2]+=t[ha[i]],t[ha[i]]=0;
                    }
                    continue;
                }
            }
        }
        for(int i =0; i<4; i++)
            if(n[i+1]==0)
            {
                cout<<"WINNER"<<endl;
                continue;
            }
            else
            {
                for(j=0; j<13; j++)
                {
                    while(p[i][ha[j]]--)
                    {
                        cout<<ha[j];
                        --n[i+1];
                        if(n[i+1])
                            cout<<" ";
                        else
                            cout<<endl;
                    }
                }
            }

    }
    return 0;
}
