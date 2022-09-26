void tarjan(int now, int pre){
    dfn[now] = low[now] = ++idx;
    for (int i = h[now]; i; i = e[i].nxt){
        int v = e[i].to;
        if (v == pre || vis[i]) continue;
        vis[i] = vis[i ^ 1] = 1;
        stk.push(i);
        if (!dfn[v]){
            tarjan(v, now);
            low[now] = min(low[now], low[v]);
            if (low[v] >= dfn[now] && now != pre){
                bcc_cnt++;
                for (int top = -1; top != i; stk.pop()){
                    top = stk.top();
                    if (blg[e[top].to] != bcc_cnt)
                        blg[e[top].to] = bcc_cnt, bcc_node[bcc_cnt].pb(e[top].to);
                    if (blg[e[top ^ 1].to] != bcc_cnt)
                        blg[e[top ^ 1].to] = bcc_cnt, bcc_node[bcc_cnt].pb(e[top ^ 1].to);
                    bcc_edge[bcc_cnt].pb(top);
                    bcc_edge[bcc_cnt].pb(top ^ 1);
                }
            }
        }
        else
            low[now] = min(low[now], dfn[v]);
    }
    //if (now == pre && ch > 0){}
}