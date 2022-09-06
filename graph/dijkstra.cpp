vector<pii> adj[N];
int dis[N];
int dijkstra(int s, int t){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0;i <= n; i++) 
        dis[i] = 2e9;
    dis[s] = 0;
    pq.push(MP(0, s));
    while(!pq.empty()){
        int now_dis = pq.top().F, now_pos = pq.top().S;
        pq.pop();
        if(now_dis != dis[now_pos]) continue;
        if(now_pos == t) break;
        for(auto j : adj[now_pos]){
            if(dis[j.F] > dis[now_pos] + j.S){
                dis[j.F] = dis[now_pos] + j.S;
                pq.push(MP(dis[j.F], j.F));
            }
        }
    }
    return dis[t];
}