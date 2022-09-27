priority_queue<pll, vector<pll>, greater<pll>> pq;
priority_queue<ll> best[N];
int n, k; // kth shortest path
void kth_shortest_path(){
    best[st].push(0);
    pq.push(MP(0, st));
    while (!pq.empty()){
        ll now = pq.top().S, now_dis = pq.top().F;
        pq.pop();
        if (now_dis > best[now].top()) continue;
        for (auto x : v[now]){
            if (best[x.F].size() < k){
                best[x.F].push(now_dis + x.S);
                pq.push(MP(now_dis + x.S, x.F));
            }
            else if (!best[x.F].empty() && now_dis + x.S < best[x.F].top()){
                best[x.F].pop();
                best[x.F].push(now_dis + x.S);
                pq.push(MP(now_dis + x.S, x.F));
            }
        }
    }
}