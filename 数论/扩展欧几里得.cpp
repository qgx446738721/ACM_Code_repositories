void Exgcd(Ll a, LL b, LL &d, LL &x, LL &y){
    if(!b) d = a, x = 1, y = 0;
    else{
        Exgcd(b, a%b, d, y, x);
        y -= a/b*x;
    }
}
//�ҳ�һ������(x, y)ʹ��ax+by=gcd(a, b)������d��gcd(a, b)

bool LinePro(Ll a, LL b, LL c, LL &x0, LL &y0, LL &a0, LL &b0){
    LL d;
    Exgcd(a, b, d, x0, y0);
    if(c%d) return false;
    a0 = a/d; b0 = b/d; x0 *= c/d; y0 *= c/d;
    return true;
}
//ax+by = c ������
