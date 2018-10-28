#include<iostream>
#include<string>
using namespace std;
int next[103][4];
int dp[100005][105];
string s;
int n,k;
string ha="AGCT";
void init()
{
    for(int i =0;i<k;i++)
        for(int j=0;j<4;j++)
        {
            string a=s.substr(0,i)+ha[j];
            while(s.substr(0,a.size())==a)
            {
                a=a.substr(1);
            }
            dp[i][j]=a.size();
        }
}
