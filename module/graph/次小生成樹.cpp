#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
#define shaman ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
struct edge{
    int x, y, val;
    bool used;
    bool operator<(const edge &tmp){return val < tmp.val;}
};
const int N = 1e3+25;
int f[N], mst = 0, smst = LLONG_MAX;
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }
vector<pii> v[N];
int in[N], out[N], idx, fa[14][N], mx[14][N];
void dfs(int now, int pre){
    in[now] = ++idx;
    for (auto x : v[now]){
        if (x.F == pre) continue;
        fa[0][x.F] = now;
        mx[0][x.F] = x.S;
        dfs(x.F, now);
    }
    out[now] = ++idx;
}
bool is_ac(int x, int y) { return in[x] <= in[y] && out[x] >= out[y];}

int query(int x, int y){
    int MX = 0;
    for (int i = 12; i >= 0; i--){
        if (!is_ac(fa[i][x], y)) MX = max(MX, mx[i][x]), x = fa[i][x];
        if (!is_ac(fa[i][y], x)) MX = max(MX, mx[i][y]), y = fa[i][y];
    }
    if (!is_ac(x, y)) MX = max(mx[0][x], MX);
    if (!is_ac(y, x)) MX = max(mx[0][y], MX);
    return MX;
}
signed main(){shaman;
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        e.pb({x, y, z, 0});
    }
    int cnt = 0;
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); i++){
        int p = Find(e[i].x), q = Find(e[i].y);
        if (p != q){
            f[p] = q;
            cnt++;
            mst += e[i].val;
            v[e[i].x].pb({e[i].y, e[i].val});
            v[e[i].y].pb({e[i].x, e[i].val});
            e[i].used = 1;
        }
    }
    if (cnt == n - 1){
        cout << mst << ' ';
        dfs(1, 1);
        fa[0][1] = 1;
        for (int i = 1; i <= 12; i++)
            for (int j = 1; j <= n; j++){
                fa[i][j] = fa[i - 1][fa[i - 1][j]];
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][fa[i - 1][j]]);
            }
        for (int i = 0; i < e.size(); i++)
            if (e[i].used == 0)
                smst = min(smst, mst - query(e[i].x, e[i].y) + e[i].val);
        if (m == n - 1)
            cout << "-1\n";
        else
            cout << smst << '\n';
    }
    else cout << "-1 -1\n";
}