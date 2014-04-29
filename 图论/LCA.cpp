const int MAX_N = 10005;
const int MAX_M = 10005;
const int MAX_Q = 10005;//ѯ�ʸ���
int ask[2][MAX_N], lca[MAX_N], dist[MAX_N];//���߱����ѯ�ʣ�����������ȣ�����
bool vist[MAX_N];
int head[MAX_N], Set[MAX_N], lp;
struct eage{
    int v, w, next;
}road[MAX_M];
void Init(int N){
    memset(head, -1, sizeof(int)*(N+1));
    memset(vist, 0, sizeof(bool)*(N+1));
    lp=0;
}
void Add_Road(int s, int e, int len){
    road[lp].v = e;
    road[lp].w = len;
    road[lp].next = head[s];
    head[s] = lp++;
}
int Find(int x){
    if(Set[x] == -1){
        return x;
    }
    return Set[x] = Find(Set[x]);
}
int N, Q;//��ĸ�����ѯ�ʸ���
void Dfs(int x){//�������lca
    vist[s] = true;
    Set[s] = -1;
    for(int i=0; i<Q; i++){
        if(ask[0][i] == s && vist[ask[1][i]]){
            lca[i] = Find(ask[1][i]);
        }
        else if(ask[1][i] == s && vist[ask[0][i]]){
            lca[i] = Find(ask[0][i]);
        }
    }
    for(int i = head[s]; ~i; i=road[i].next){
        if(!vist[road[i].v]){
            dist[road[i].v] = dist[s] + road[i].w;
            Dfs(road[i].v);
            Set[road[i].v] = s;
        }
    }
}
