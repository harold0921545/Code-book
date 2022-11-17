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
vector<pii> v;
double dis(int a, int b) { return sqrt((double)(v[a].F - v[b].F) * (v[a].F - v[b].F) + (double)(v[a].S - v[b].S) * (v[a].S - v[b].S)); }
bool cmpbyX(pii a, pii b) { return a.F < b.F || (a.F == b.F && a.S < b.S); }
bool cmpbyY(int a, int b) { return v[a].S < v[b].S || (v[a].S == v[b].S && v[a].F < v[b].F); }
double solve(int l,int r){
    double d = 1 << 30;
    if (l == r)
        return d;
    if (l + 1 == r)
        return dis(l, r);
    int mid = l + r >> 1;
    double d1 = solve(l, mid);
    double d2 = solve(mid + 1, r);
    d = min(d1, d2);
    vector<int> tmp;
    for (int i = l; i <= r; i++)
        if (abs(v[i].F - v[mid].F) <= d)
            tmp.pb(i);
    sort(tmp.begin(), tmp.end(), cmpbyY);
    for (int i = 0; i < tmp.size(); i++)
        for (int j = i + 1; j < tmp.size() && v[tmp[j]].S - v[tmp[i]].S < d; j++)
            d = min(d, dis(tmp[i], tmp[j]));
    return d;
}

signed main(){
    int n;
    cin >> n;
    for (int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        v.pb({x, y});
    }
    sort(v.begin(), v.end(), cmpbyX);
    cout  <<solve(0, n - 1) << "\n";
}
