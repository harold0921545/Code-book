const int N; // range * 2
vector<int> v[N];
bool instk[N];
stack<int> stk;
int dfn[N], low[N], idx, blg[N], scc;
// a -> b = if a then b
void tarjan(int now){
    dfn[now] = low[now] = ++idx;
    instk[now] = 1;
    stk.push(now);
    for (auto x : v[now]){
        if (!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }
        else if (instk[x])
            low[now] = min(low[now], dfn[x]);
    }
    if (dfn[now] == low[now]){
        scc++;
        for (int top = -1; top != now; stk.pop()){
            top = stk.top();
            blg[top] = scc;
            instk[top] = 0;
        }
    }
}
bool twosat(){
    for (int i = 1; i <= 2 * n; i++)
        if (!dfn[i])
            tarjan(i);
    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (blg[i] == blg[i + n])
            ok = false;
    if (!ok)
        return false;
    else{
        return true;
        // construct ans
        vector<int> ans;
        for(int i = 1; i <= n; i++)
            if(blg[i] < blg[i + n])
                ans.pb(0); // choose i
            else 
                ans.pb(1); // coose i + n
    }
}