//PB��������ǰ��MR��������ÿ�ο��Էֽ��һ������(��һ��������)����Ҫ���MR
LL PB(LL n, int c=12323, int x0=2){
    if(~n & 1) return 2;
    LL x, y, d = 1, k = 0, i = 1;
    x = y = x0;
    while(true){
        x = (MulMod(x, x+n) + c)%n;     //f(x) = x*x+c, c���Ի�����������
        d = gcd(n+x-y, n);
        if(d!=1 && d<n) return d;       //���һֱTLE������d<=n
        if(y==x) return n;
        if(++k == i) y = x, i<<=1;
    }
}

//�ֽ�����������
LL s[110]; int l=0;
void gn(LL n, int op = 12323){
    if(isp(n)){
        s[l++] = n;
        return;
    }
    LL x = PB(n);
    while(x==n) x = PB(n, --op);
    gn(x);
    gn(n/x);
}
//����gn(n);�ֽ⣬����s��l��ʼ�������ú�sort(s, s+l);����õ����е�����
//opһ�㲻��Ҫ��
