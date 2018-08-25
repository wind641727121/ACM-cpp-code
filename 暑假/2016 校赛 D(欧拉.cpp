

给出一个N，求1..N中与N互质的数的和

ifgcd(n,i)=1 then gcd(n,n-i)=1 (1<=i<=n)

反证法：

        如果存在K!=1使gcd(n,n-i)=k,那么(n-i)%k==0

        而n%k=0

        那么必须保证i%k=0

        k是n的因子,如果i%k=0那么 gcd(n,i)=k,矛盾出现;

        于是问题变的非常简单： ANS=N*phi(N)/2

        i,n-i总是成对出现，并且和是n

       于是可能就有人问了，如果存在n-i=i那不是重复计算？

        答案是不会

        因为:

                n=2*i->i=n/2

1.如果n是奇数，那么n!=2*i,自然也不存在 n-i=i和重复计算之说

2.如果n是偶数,n=2*i成立,gcd(n,n/2)必然为n的一个因子,这个因子为1当且仅当n==2

3.于是对于n>2的偶数，绝对不存在gcd(n,n/2)=1所以更别说什么重复计算了

        对于n==2

        ans=2*1/2=1，正好也满足

        所以得到最终公式：

       　　　　　　　　　　 ans=N*phi(N)/2 
	   /*
 求所有小于N且与N不互质的数的和。
 若：gcd(n,m)=1,那么gcd(n,n-m)=1;
 sum(n)=phi(n)*n/2; //sum(n)为小于n的所有与n互质的数的和
                    //phi(n)为小于n的所有与n互质的数的个数
*/
#include<cmath>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long LL;
using namespace std;
LL euler(LL n)
{
    LL m=(int)sqrt(n+0.5);
    LL ans=n;
    for(LL i=2;i<=m;i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    if(n>1)
        ans=ans/n*(n-1);
    return ans;
}
int main ()
{
    LL n;
    while(scanf("%lld",&n),n)
    {
        LL sum=n*(n-1)>>1;
        LL t=euler(n)*n>>1;
        sum-=t;
        printf("%lld\n",sum%1000000007);
    }
}
