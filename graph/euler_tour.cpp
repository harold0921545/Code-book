set<int> adj[N];
vector<int> ans;
void dfs(int now){
    while (!adj[now].empty()){
        int x = *adj[now].begin();
        adj[now].erase(adj[now].find(x));
        adj[x].erase(adj[x].find(now));
        dfs(x);
    }
    ans.pb(now);
}

bool euler_tour(){
    int st = 1, cnt = 0;
    for(int i = n; i; i--){
        if (adj[i].size() % 2 == 1)
            st = i, cnt++;
    }
    if (cnt > 2) return false;
    else{
        return true;
        dfs(st);
        reverse(ans.begin(), ans.end());
    }
}