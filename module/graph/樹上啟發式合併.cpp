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
/*
    O(N log N)
    走輕邊時子樹大小最少會除以二。
    若節點為輕子節點，每次計算完要刪除。
*/
const int N = 2e4 + 25;
vector<int> v[N];
int c[N], hson[N], in[N], out[N], node[N], sz[N], idx;
int ans[N], cnt[N], tot;
void add(int x){
    if (cnt[c[x]] == 0)
        tot++;
    cnt[c[x]]++;
}
void del(int x){
    cnt[c[x]]--;
    if (cnt[c[x]] == 0)
        tot--;
}
void dfs1(int now, int pre){
    in[now] = ++idx;
    node[idx] = now;
    sz[now] = 1;
    for (auto x : v[now]){
        if (x == pre) continue;
        dfs1(x, now);
        sz[now] += sz[x];
        if (!hson[now] || sz[x] > sz[hson[now]]) hson[now] = x;
    }
    out[now] = idx;
}
void dfs2(int now, int pre, bool hv){
    for (auto x : v[now]){
        if (x == pre || x == hson[now]) continue;
        dfs2(x, now, 0);
    }
    if (hson[now] > 0) dfs2(hson[now], now, 1);
    for (auto x : v[now]){
        if (x == pre || x == hson[now]) continue;
        for (int i = in[x]; i <= out[x]; i++)
            add(node[i]);
    }
    add(now);
    ans[now] = tot;
    if (hv == 0)
        for (int i = in[now]; i <= out[now]; i++)
            del(node[i]);
}
signed main(){shaman;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}