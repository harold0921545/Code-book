void tarjan(int now){
    dfn[now] = low[now] = ++idx;
    stk.push(now);
    instk[now] = true;
    for (auto x : v[now]){
        if (!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }
        else if (instk[x])
            low[now] = min(low[now], dfn[x]);
    }
    if (low[now] == dfn[now]){
        scc_idx++;
        for (int top = -1; top != now; stk.pop()){
            top = stk.top();
            blg[top] = scc_idx;
            instk[top] = false;
        }
    }
}
