//#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define ls rt<<1
#define rs rt<<1|1
#define debug(x) cerr << #x << " = " << x << "\n"
#define re register
#define shaman ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
vector<pii> v[250005];
vector<int> g[250005];
bool qy[250005];
int dep[250005], stk[250005], in[250005], out[250005], idx, fa[20][250005], mi[250005], node[550005];
bool is_ac(int a,int b){return in[a] <= in[b] && out[a] >= out[b];}
void dfs(int now, int pre){
    in[now] = ++idx;
    fa[0][now] = pre;
    for (auto x : v[now]){
        if (x.F == pre)
            continue;
        dep[x.F] = dep[now] + 1;
        mi[x.F] = min(mi[now], x.S);
        dfs(x.F, now);
    }
    out[now] = ++idx;
}
void build(int n){
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n;j++)
            fa[i][j] = fa[i - 1][fa[i - 1][j]];
}
int LCA(int a, int b){
    if (is_ac(a, b))
        return a;
    if (is_ac(b, a))
        return b;
    for (int i = 19; i >= 0; i--){
        if (!is_ac(fa[i][a], b))
            a = fa[i][a];
    }
    return fa[0][a];
}
int calc(int now){
    int sum = 0, res = 0;
    for (auto x : g[now])
        sum += calc(x);
    if (qy[now])
        res = mi[now];
    else
        res = min(mi[now], sum);
    qy[now] = false;
    g[now].clear();
    return res;
}
signed main(){shaman;
    int n, m, top;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({y, z});
        v[y].pb({x, z});
    }
    mi[1] = 1e18;
    dep[1] = 1;
    dfs(1, 1);
    build(n);
    cin >> m;
    while (m--){
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> node[i], qy[node[i]] = 1;
        sort(node + 1, node + k + 1, [&](int x, int y)
             { return in[x] < in[y]; });
        stk[top = 1] = node[1];
        for (int i = 2; i <= k; i++){
            int lca = LCA(node[i], node[i - 1]);
            while (1){
                if (dep[lca] >= dep[stk[top - 1]]){
                    if (lca != stk[top]){
                        g[lca].pb(stk[top]);
                        if (lca != stk[top - 1])
                            stk[top] = lca;
                        else
                            top--;
                    }
                    break;
                }
                else{
                    g[stk[top - 1]].pb(stk[top]);
                    top--;
                }
            }
            stk[++top] = node[i];
        }
        while (--top)
            g[stk[top]].pb(stk[top + 1]);
        cout << calc(stk[1]) << '\n';
    }
}
