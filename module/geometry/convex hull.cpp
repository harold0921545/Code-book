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
int cross(pii a, pii b){return a.F * b.S - a.S * b.F;}
signed main(){shaman;
    int n;
    cin >> n;
    vector<pii> node;
    for (int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        node.pb({x, y});
    }
    sort(node.begin(), node.end());
    vector<pii> hull, ans;
    for (int i = 0; i < node.size(); i++){
        while (hull.size() >= 2){
            int sz = hull.size() - 1;
            if (cross({hull[sz].F - hull[sz - 1].F, hull[sz].S - hull[sz - 1].S}, {node[i].F - hull[sz - 1].F, node[i].S - hull[sz - 1].S}) >= 0)
                hull.pop_back();
            else
                break;
        }
        hull.pb(node[i]);
    }
    ans = hull;
    hull.clear();
    for (int i = 0; i < node.size(); i++){
        while (hull.size() >= 2){
            int sz = hull.size() - 1;
            if (cross({hull[sz].F - hull[sz - 1].F, hull[sz].S - hull[sz - 1].S}, {node[i].F - hull[sz - 1].F, node[i].S - hull[sz - 1].S}) <= 0)
                hull.pop_back();
            else
                break;
        }
        hull.pb(node[i]);
    }
    for (int i = hull.size() - 2; i >= 0; i--)
        ans.pb(hull[i]);
    int res = 0;
    for (int i = 1; i < ans.size() ; i++)
        res += (cross(ans[i], ans[i - 1]));
    cout << (res + 1) / 2 << '\n';
}
