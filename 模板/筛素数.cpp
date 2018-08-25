void makeprime(int n){
    memset(f,true,sizeof(f));
    f[0]=f[1]=false;
    for (int i=2;i<=n;i++){
        if (f[i]) prime[++t]=i;//prime´æÖÊÊý
        for (int j=1;j<=t&&i*prime[j]<=n;j++){
            f[i*prime[j]]=false;
            if (i%prime[j]==0) break;
        }
    }
}
