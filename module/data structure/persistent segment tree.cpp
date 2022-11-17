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
const int N = 1e6+25;
int a[N], rt[N * 20], lc[N * 20], rc[N * 20], seg[N*20], idx;

void build(int l,int r,int &p){
    p = ++idx;
    if(l==r){
        seg[p] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, lc[p]);
    build(mid + 1, r, rc[p]);
}

void upd(int l,int r,int &p,int pre,int q,int k){
    p=++idx;
    lc[p] = lc[pre], rc[p] = rc[pre], seg[p] = seg[pre];
    if(l==r){
        seg[p] = k;
        return;
    }
    int mid = l + r >> 1;
    if (q <= mid)
        upd(l, mid, lc[p], lc[pre], q, k);
    else
        upd(mid + 1, r, rc[p], rc[pre], q, k);
}

int qy(int l,int r,int p,int q){
    if (l == r)
        return seg[p];
    int mid = l + r >> 1;
    if (q <= mid)
        return qy(l, mid, lc[p], q);
    else
        return qy(mid + 1, r, rc[p], q);
}

signed main(){shaman
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, rt[0]);
    for (int i = 1; i <= m; i++){
        int pre, opt, loc, v;
        cin >> pre >> opt >> loc;
        if (opt == 1){
            cin >> v;
            upd(1, n, rt[i], rt[pre], loc, v);
        }
        else{
            cout << qy(1, n, rt[pre], loc) << "\n";
            rt[i] = rt[pre];
        }
    }
}
