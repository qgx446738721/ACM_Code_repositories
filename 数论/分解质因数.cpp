void gn(LL n, int &l, int b[], int f[]){//l�����ӵĸ��� b[]������ f[]��Ӧָ��
    int i = 0, t;
    l = 0;
    while(n > l){
        if(n < MAX_N) t = pr[n];
        else{
            t = n;
            for(;i<lp && n/p[i] >= p[i]; i++){
                if(n%p[i] == 0){
                    t = p[i];
                    break;
                }
            }
        }
        f[l] = 0;
        while(n%t==0){
            n/=t;f[l]++;
        }
        b[l++] = t;
    }
}
