int n;
struct bipartite_graph_matching{
    int adj[N][N], a[N], vis[N];

    void init(){
        memset(adj, 0, sizeof(adj));
        memset(a, -1, sizeof(a));
    }
    bool DFS(int x){
        if (vis[x])
            return false;
        vis[x] = 1;
        for (int i = 1; i <= n; i++){
            if (adj[x][i] && (a[i] == -1 || DFS(a[i])))
                return a[i] = x, 1;
        }
        return false;
    }
    int match(){
        int res = 0;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            res += DFS(i);
        }
        return res;
    }
};
