#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int L=100005;
int na[L];
string mul(string a,int b)//�߾���a�˵�����b
{
    string ans;
    int La=a.size();
    fill(na,na+L,0);
    for(int i=La-1;i>=0;i--) na[La-i-1]=a[i]-'0';
    int w=0;
    for(int i=0;i<La;i++) na[i]=na[i]*b+w,w=na[i]/10,na[i]=na[i]%10;
    while(w) na[La++]=w%10,w/=10;
    La--;
    while(La>=0) ans+=na[La--]+'0';
    return ans;
}
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            string a="2";
            int b;
            cin>>b;
            if(b==0) {cout<<1<<endl;continue;}
            b--;
            while(b--)
             a=mul(a,2);
             cout<<a<<endl;
        }
    }
    return 0;

}
