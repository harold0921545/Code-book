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
const int MOD = 1e9 + 7;
const int bas = 107;
vector<int> v[55];
int sz[55], dep[55], h[55], p[55];
pii has[55];
int n, rtmx, rt, rtt;
void findrt(int now, int pre){
    sz[now] = 1;
    int mx = 0;
    for (auto x : v[now]){
        if (x == pre)
            continue;
        findrt(x, now);
        sz[now] += sz[x];
        mx = max(mx, sz[x]);
    }
    mx = max(mx, n - sz[now]);
    if (mx < rtmx)
        rt = now, rtmx = mx, rtt = 0;
    else if (mx == rtmx)
        rtt = now;
}
void dfs(int now, int pre){
    h[now] = dep[now] * p[1] % MOD;
    sz[now] = 1;
    for (auto x : v[now]){
        if (x == pre)
            continue;
        dep[x] = dep[now] + 1;
        dfs(x, now);
    }
    vector<pii> tmp;
    for (auto x : v[now]){
        if (x == pre)
            continue;
        tmp.pb({h[x], sz[x]});
    }
    for (auto x : tmp){
        (h[now] += x.F * p[x.S] % MOD) %= MOD;
        sz[now] += x.S;
    }
}
signed main(){shaman;
    int t;
    cin >> t;
    p[0] = 1;
    for (int i = 1; i <= 50; i++)
        (p[i] = p[i - 1] * bas) %= MOD;
    for (int k = 1; k <= t; k++){
        cin >> n;
        rtmx = MOD;
        for (int i = 0; i <= n; i++)
            v[i].clear(), sz[i] = dep[i] = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if (x)
                v[i].pb(x), v[x].pb(i);
        }
        findrt(1, -1);
        dep[rt] = 1;
        dfs(rt, -1);
        has[k].F = h[rt];
        if (rtt){
            dep[rtt] = 1;
            dfs(rtt, -1);
            has[k].S = h[rtt];
        }
        if (has[k].S > has[k].F) swap(has[k].F, has[k].S);
    }
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= i; j++){
            if (has[i] == has[j]){
                cout << j << '\n';
                break;
            }
        }
}
