bool MR(LL n, LL a){
    if(n==2) return true;
    LL d = n - 1, t;
    if(d&1) return false;
    while(~d&1) d >>= 1;
    t = PowMod(a, d, n);
    while(d!=n-1 && t!=1 && t!=n-1){
        d <<= 1;
        t = MulMod(t, t, n);
    }
    return (t == n-1) || (d&1);
}
//�����isp��������true����������ע�⴫���С����
bool isp(int n){    //������Χ
    if(n == 1) return false;
    if(n == 2|| n == 7 || n == 61) return true;
    return MR(N, 2) && MR(n, 7) && MR(n, 61);
}
bool isp(LL, n){    //(2^54)��Χ
    if(n==1 || n==46856248255981LL) return false;
    if(n==2 || n==3 || n==7 || n==61 || n==24251) return true;
    return MR(n, 2) && MR(n, 3) && MR(n, 7) && (n, 61) && (n, 24251);
}
//���Ҫ����long long ��Χ������2,3,5,7,11,13,17,19,23
//�Ƽ���if����2^54���ʹ��
