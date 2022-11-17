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
const int N=250005;
int a[N], v[N], seg[N * 20], lc[N * 20], rc[N * 20], rt[N * 20], idx;
void build(int l,int r,int &p){
    p = ++idx;
    if(l==r){
        seg[p] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, lc[p]);
    build(mid + 1, r, rc[p]);
}
void upd(int l,int r,int &p,int pre,int k){
    p = ++idx;
    lc[p] = lc[pre], rc[p] = rc[pre], seg[p] = seg[pre] + 1;
    if(l==r) return;
    int mid = l + r >> 1;
    if(k<=mid)
        upd(l, mid, lc[p], lc[pre], k);
    else
        upd(mid + 1, r, rc[p], rc[pre], k);
}
int qy(int l,int r,int L,int R,int k){
    if (l == r)
        return l;
    int cur = seg[lc[R]] - seg[lc[L]], mid = l + r >> 1;
    if (cur >= k)
        return qy(l, mid, lc[L], lc[R], k);
    else
        return qy(mid + 1, r, rc[L], rc[R], k - cur);
}

signed main(){shaman 
    int n, q;
    cin >> n >> q;
    vector<int> lisan;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        v[i] = a[i];
        lisan.pb(a[i]);
    }
    sort(lisan.begin(), lisan.end());
    lisan.resize(unique(lisan.begin(), lisan.end()) - lisan.begin());
    for (int i = 1; i <= n; i++)
        a[i] = upper_bound(lisan.begin(), lisan.end(), a[i]) - lisan.begin();
    int nn = lisan.size();
    build(1, nn, rt[0]);
    for (int i = 1; i <= n; i++)
        upd(1, nn, rt[i], rt[i - 1], a[i]);
    while(q--){
        int L, R, k;
        cin >> L >> R >> k;
        cout << lisan[qy(1, nn, rt[L - 1], rt[R], k)-1] << "\n";
    }
}