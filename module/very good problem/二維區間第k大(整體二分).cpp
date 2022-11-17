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
mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
vector<pii> pos[300000];
struct query{
    int x1, x2, y1, y2, c, id;
};
int ans[300005], bit[505][505], a[505][505];
int n, q;
void upd(int x, int y, int k){
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= n; j += j & -j)
            bit[i][j] += k;
}
int quy(int x, int y){
    int res = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            res += bit[i][j];
    return res;
}
int gt_ans(int x1, int y1, int x2, int y2){
    return quy(x2, y2) - quy(x1 - 1, y2) - quy(x2, y1 - 1) + quy(x1 - 1, y1 - 1);
}
void solve(int l,int r,vector<query> qy){ //l~r => ans
    if (l == r){
        for (int i = 0; i < qy.size(); i++)
            ans[qy[i].id] = l;
        return;
    }
    vector<query> ql, qr;
    int mid = l + r >> 1;
    for (int i = l; i <= mid; i++)
        for (int j = 0; j < pos[i].size(); j++){
            int x = pos[i][j].F, y = pos[i][j].S;
            upd(x, y, 1);
        }
    for (int i = 0; i < qy.size(); i++){
        int tmp = gt_ans(qy[i].x1, qy[i].y1, qy[i].x2, qy[i].y2);
        if (tmp >= qy[i].c)
            ql.pb(qy[i]);
        else{
            qy[i].c -= tmp;
            qr.pb(qy[i]);
        }
    }
    for (int i = l; i <= mid; i++)
        for (int j = 0; j < pos[i].size(); j++){
            int x = pos[i][j].F, y = pos[i][j].S;
            upd(x, y, -1);
        }
    solve(l, mid, ql);
    solve(mid + 1, r, qr);
}
signed main(){shaman;
    cin >> n >> q;
    vector<int> lisan;
    vector<query> qy(q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            lisan.pb(a[i][j]);
        }
    sort(lisan.begin(), lisan.end());
    lisan.resize(unique(lisan.begin(), lisan.end()) - lisan.begin());
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            a[i][j] = upper_bound(lisan.begin(), lisan.end(), a[i][j]) - lisan.begin();
            pos[a[i][j]].pb({i, j});
        }
    for (int i = 0; i < q; i++){
        cin >> qy[i].x1 >> qy[i].y1 >> qy[i].x2 >> qy[i].y2 >> qy[i].c;
        qy[i].id = i;
    }
    solve(1, lisan.size(), qy);
    for (int i = 0; i < q; i++)
        cout << lisan[ans[i] - 1] << '\n';
}