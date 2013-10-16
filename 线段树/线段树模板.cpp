//�������Ҷ��Ӻ궨��
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
const int MAXN=100000;//������
int tree[MAXN<<2];//�����߶���������
//���ϸ���
void PushUp(int id)
{
	tree[id]=tree[id<<1]+tree[id<<1|1];//������Ҫд���²���
}
//�����߶���
void Build(int l,int r,int id)
{
	if(l==r)
	{
		cin>>tree[id];
		return;
	}
	int mid=(l+r)>>1;
	Build(lson),Build(rson);
	PushUp(id);
}
//�������
void Update(int x,int c,int l,int r,int id)
{
	if(l==r&&x==l)
	{
		tree[id]+=c;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		Update(x,c,lson);
	}
	else
	{
		Update(x,c,rson);
	}
	PushUp(id);
}
//�������
void Update(int L,int R,int c,int l,int r,int id)
{
	if(L<=l&&r<=R)
	{
		tree[id]+=c*(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)
	{
		Update(L,R,c,lson);
	}
	if(R>mid)
	{
		Update(L,R,c,rson);
	}
	PushUp(id);
}
//�����ѯ
int Query(int x,int l,int r,int id)
{
	if(l==r&&r==x)
	{
		return tree[id];
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	{
		return Query(x,lson);
	}
	else
	{
		return Query(x,rson);
	}
}
//�����ѯ
int Query(int L,int R,int l,int r,int id)
{
	if(L<=l&&r<=R)
	{
		return tree[id];
	}
	int mid=(l+r)>>1;
	if(R<=mid)
	{
		return Query(L,R,lson);
	}
	else if(L>mid)
	{
		return Query(L,R,rson);
	}
	else
	{
		return Query(L,R,lson)+Query(L,R,rson);
	}
}