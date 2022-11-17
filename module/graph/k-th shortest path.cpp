#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
 
#define F first
#define S second
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;
#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"
 
const int N = 1e5 + 25;
vector<pll> v[N];
priority_queue<pll, vector<pll>, greater<pll>> pq;
priority_queue<ll> best[N];
int n, m, k;
 
signed main(){noTLE;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb(MP(y, z));
    }
    best[1].push(0);
    pq.push(MP(0, 1));
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
    vector<ll> ans;
    while (!best[n].empty()){
        ans.pb(best[n].top());
        best[n].pop();
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}