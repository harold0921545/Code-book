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
const int maxn = 2e5 + 10;
vector<pii> v[maxn];
int n, m, sum;
bool vis[maxn], tf[10000010], ans[maxn];
int mx[maxn], sz[maxn], rt, q[maxn], dis[maxn];
void dfs(int now, int pre){
    sz[now] = 1, mx[now] = 0;
    for (auto x : v[now]){
        if (x.F == pre || vis[x.F])
            continue;
        dfs(x.F, now);
        mx[now] = max(mx[now], sz[x.F]);
        sz[now] += sz[x.F];
    }
    mx[now] = max(mx[now], sum - sz[now]);
    if (mx[now] < mx[rt])
        rt = now;
}
int cnt, dd[maxn];
void calc(int now, int pre){
    dd[++cnt] = dis[now]; 
    for (auto x : v[now]){
        if (x.F == pre || vis[x.F])
            continue;
        dis[x.F] = dis[now] + x.S;
        calc(x.F, now);
    }
}
queue<int> tag;
void solve(int now, int pre){
    tf[0] = true;
    tag.push(0);
    vis[now] = true;
    for (auto x : v[now]){
        if (x.F == pre || vis[x.F])
            continue;
        dis[x.F] = x.S;
        calc(x.F, now);
        for (int k = 1; k <= cnt; k++)
            for (int i = 1; i <= m; i++)
                if (q[i] >= dd[k])
                    ans[i] |= tf[q[i] - dd[k]];
        for (int k = 1; k <= cnt; k++)
            if (dd[k] < 10000010)
                tag.push(dd[k]), tf[dd[k]] = true;
        cnt = 0;  
    }
    while (!tag.empty())
        tf[tag.front()] = false, tag.pop();
    for (auto x : v[now]){
        if (x.F == pre || vis[x.F])
            continue;
        sum = sz[x.F];
        rt = 0;
        mx[rt] = 1e18;
        dfs(x.F, now);
        dfs(rt, -1);
        solve(rt, now);
    }
}
signed main(){shaman;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({y, z});
        v[y].pb({x, z});
    }
    for (int i = 1; i <= m; i++)
        cin >> q[i];
    rt = 0;
    mx[rt] = 1e18;
    sum = n;
    dfs(1, -1);
    dfs(rt, -1);
    solve(rt, -1);
    for (int i = 1; i <= m; i++){
        if (ans[i])
            cout << "AYE\n";
        else
            cout << "NAY\n";
    }
}
