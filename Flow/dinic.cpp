//O(MN^2)
int idx = 2, h[N], lev[N];
struct edge{
    int to, nxt, val;
}e[M];
int n, m, ed, st;
void add(int u,int v,int vl){
    e[idx].to = v;
    e[idx].nxt = h[u];
    e[idx].val = vl;
    h[u] = idx++;
}
bool bfs(){
    memset(lev, -1, sizeof(lev));
    queue<int> q;
    q.push(st);
    lev[st] = 1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = h[now]; i != 0; i = e[i].nxt){
            int x = e[i].to, vl = e[i].val;
            if (vl && lev[x] == -1){
                lev[x] = lev[now] + 1;
                q.push(x);
            }
        }
    }
    return lev[ed] != -1;
}
int dfs(int now, int in){
    if (now == ed)
        return in;
    int out = 0;
    for (int i = h[now]; i != 0; i = e[i].nxt){
        int x = e[i].to, vl = e[i].val;
        if (vl && lev[x] == lev[now] + 1){
            int tmp = dfs(x, min(vl, in));
            e[i].val -= tmp;
            e[i ^ 1].val += tmp;
            in -= tmp;
            out += tmp;
        }
    }
    if (out == 0) lev[now] = -1;
    return out;
} 
int dinic(){
    int res = 0;
    while(bfs())
        res += dfs(st, inf);
    return res;
}
