//Ps: ����ѡȡα���������Ϊ F(x)= x*x+c ��Ĭ�� c = 12323��ע�����ֻ�ֽܷ� 2^62-1��
//�ֽ�ʧ��(���� n)�ͳ��Ա任 c,c ����ȡ 0 ��-2������ʧ��,���Ա任 X0
//PB ��������ǰ�� MR ������,ÿ�ο��Էֽ��һ������(��һ��������),����� MR �㷨��
ll PB(ll n,int c=12323,int x0=2){
    if(~n&1) return 2;
    ll x,y,d=1,k=0,i=1;
    x=y=x0;
    while(1){
	x=(mulmod(x,x,n)+c)%n;
	//f(x)=x*x+c,c �ɻ� 24251 ����������
	d=gcd(n+x-y,n);
	if(d!=1 && d<n) return d; //��Ī������һֱ TLE �ɳ��� d<n �ĳ� d<=n,Ŀǰû������
	if(y==x) return n;
	if(++k == i) y=x,i<<=1;
    }
}
//�ֽ�����������
ll s[110];int l=0;
void gn(ll n,int op=12323){
    if(isp(n)) {s[l++]=n;return;}
    ll x=PB(n);
    while(x==n) x=PB(n,--op);
    gn(x);
    gn(n/x);
}
//���� gn(n);�ֽ�,����ǰ s �� l ��ʼ��,���ú� sort(s,s+l);����õ�����������,���ִ�����ָ��
//op һ�㲻��Ҫ��
