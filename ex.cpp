#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[200005][15];
int main()
{
    ios::sync_with_stdio(0);
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
            {
                cin>>a[i][0];
                a[i][0]=a[i][0]%k;
                for(int j =1;j<n;j++)
                    a[i][j]=(a[i][0]+10%k)%k;
            }

        for(int i=0;i<n;i++)

    }
    return 0;
}
