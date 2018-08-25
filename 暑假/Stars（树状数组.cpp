#include<cstdio>
#include<cstring>
#define MAX_N 32005
int tre[32005],level[15005];
int lowbit(int x){
    return x&-x;
}
int sum(int i){
    int ans=0;
   while(i>0){
        ans+=tre[i];
        i=i-lowbit(i);
    }
    return ans;
}
void add(int i){
   while(i<=MAX_N){
         tre[i]+=1;
        i=i+lowbit(i);
    }
}
int main(){
    int n,i,a,b;
    while(scanf("%d",&n)!=EOF){
        memset(tre,0,sizeof(tre));
        memset(level,0,sizeof(level));
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            a++;
            level[sum(a)]++;
            add(a);
        }
        for(int i=0; i<n; ++i)
            printf("%d\n",level[i]);
    }
}
