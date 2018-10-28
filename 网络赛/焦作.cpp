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
#define bug1(g) cout<<"test: "<<g<<endl
#define bug2(g,i) cout<<"test: "<<g<<" "<<i<<endl
#define bug3(g,i,k) cout<<"test: "<<g<<" "<<i<<" "<<k<<endl
const int maxn =405;
struct bign{
     int d[maxn], len;
    void clean() { while(len > 1 && !d[len-1]) --len ; }
    bign()             { memset(d, 0, sizeof(d)); len = 1; }
    bign(int num)     { *this = num; }
    bign(char* num) { *this = num; }
    bign operator = (const char* num){
        memset(d, 0, sizeof(d)); len = strlen(num);
        for(register int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';
        clean();
        return *this;
    }
    bign operator = (int num){
        char s[20]; sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator + (const bign& b){
        bign c = *this; register int i;
        for (i = 0; i < b.len; ++i ){
            c.d[i] += b.d[i];
            if (c.d[i] > 9) c.d[i]%=10, ++c.d[i+1] ;
        }
        while (c.d[i] > 9) c.d[i++]%=10, ++c.d[i] ;
        c.len = max(len, b.len);
        if (c.d[i] && c.len <= i) c.len = i+1;
        return c;
    }
    bign operator - (const bign& b){
        bign c = *this;register int i;
        for (i = 0; i < b.len; ++i ){
            c.d[i] -= b.d[i];
            if (c.d[i] < 0) c.d[i]+=10, --c.d[i+1] ;
        }
        while (c.d[i] < 0) c.d[i++]+=10, --c.d[i] ;
        c.clean();
        return c;
    }
    bign operator * (const bign& b)const{
       register int i, j; bign c; c.len = len + b.len;
        for(j = 0; j < b.len; ++j ) for(i = 0; i < len; ++i )
            c.d[i+j] += d[i] * b.d[j];
        for(i = 0; i < c.len-1; ++i )
            c.d[i+1] += c.d[i]/10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    bign operator / (const bign& b){
      register  int i, j;
        bign c = *this, a = 0;
        for (i = len - 1; i >= 0; --i )
        {
            a = a*10 + d[i];
            for (j = 0; j < 10; ++j ) if (a < b*(j+1)) break;
            c.d[i] = j;
            a = a - b*j;
        }
        c.clean();
        return c;
    }
    bign operator % (const bign& b){
        int i, j;
        bign a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a*10 + d[i];
            for (j = 0; j < 10; ++j) if (a < b*(j+1)) break;
            a = a - b*j;
        }
        return a;
    }
  //  bign operator += (const bign& b){
     //   *this = *this + b;
     //   return *this;
   // }
    bool operator <(const bign& b) const{
         if(len != b.len) return len < b.len;
        for(register int i = len-1; i >= 0; --i )
          if(d[i] != b.d[i]) return d[i] < b.d[i];
 return false;
     }
    bool operator >(const bign& b) const{return b < *this;}
   // bool operator<=(const bign& b) const{return !(b < *this);}
   // bool operator>=(const bign& b) const{return !(*this < b);}
   // bool operator!=(const bign& b) const{return b < *this || *this < b;}
 bool operator==(const bign& b) const{return !(b < *this) && !(b > *this);}
  string str() const{
        char s[maxn]={};
        for(register int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';
        return s;
            }
} n,a;

istream& operator >> (istream& in, bign& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
//ostream& operator << (ostream& out, const bign& x)
//{
//    out << x.str();
//    return out;
//}
typedef long long ll;
inline int is(bign n)
{
    if(n==0) return 1;
   register int g = n.d[n.len-1];
    if(g==2||g==3||g==7||g==8)return 0;
    if(n.len>=2)
    {
        int d = n.d[n.len-2];
        if((d+g)%2==1) return 0;
        if(g==6&&d%2==0)return 0;
    }
      ll ha=0;
     for(int i = 0;i<n.len;++i )

      ha=(ha+n.d[i])%10;
    if(ha==2||ha==3||ha==5||ha==6||ha==8) return 0;
    if(n%3==2||n%4==2||n%4==3||n%5==2||n%5==3
       ||n%8==2||n%8==3||n%8==5||n%8==6||n%8==7)return 0;

    return 1;
}
inline void read()
{
    int len=0;
    char c;
    c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c<='9'&&c>='0')
    {
        n.d[len++]=c-'0';
        c=getchar();
    }
    n.len=len;
}
int n1,a1;
int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin>>t;
        while(t--){
          cin>>n;
            //cout<<n<<endl;
            a = n*(n-1)/2;
              n1= is(n);
             a1 = is(a);
            if(n1==1&&a1==1)cout<<"Arena of Valor\n";
            else if(n1==1&&a1==0) cout<<"Hearth Stone\n";
            else if(n1==0&&a1==1) cout<<"Clash Royale\n";
            else cout<<"League of Legends\n";
            }
        return 0;
}

