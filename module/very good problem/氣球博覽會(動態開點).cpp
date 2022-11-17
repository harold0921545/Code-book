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
const int N = 2e5 + 25, C = 16777217;
int a[N], rt[C], lc[N * 50], rc[N * 50], idx;
struct Seg{
    int mxl, mxr, mx;
} seg[N * 50];

void pull(int l, int r, int p){//乖乖處理好ㄅ，別亂開點
    int mid = l + r >> 1;
    if (!lc[p] && !rc[p])
        seg[p].mx = seg[p].mxl = seg[p].mxr = r - l + 1;
    else if (!lc[p] && rc[p]){
        seg[p].mxl = mid - l + 1 + seg[rc[p]].mxl;
        seg[p].mxr = seg[rc[p]].mxr + (seg[rc[p]].mxr == r - mid ? mid - l + 1 : 0);
        seg[p].mx = max(mid - l + 1 + seg[rc[p]].mxl, seg[rc[p]].mx);
    }
    else if (lc[p] && !rc[p]){
        seg[p].mxl = seg[lc[p]].mxl + (seg[lc[p]].mxl == mid - l + 1 ? r - mid : 0);
        seg[p].mxr = r - mid + seg[lc[p]].mxr;
        seg[p].mx = max(r - mid + seg[lc[p]].mxr, seg[lc[p]].mx);
    }
    else{
        seg[p].mxl = seg[lc[p]].mxl + (seg[lc[p]].mxl == mid - l + 1 ? seg[rc[p]].mxl : 0);
        seg[p].mxr = seg[rc[p]].mxr + (seg[rc[p]].mxr == r - mid ? seg[lc[p]].mxr : 0);
        seg[p].mx = max({seg[lc[p]].mx, seg[rc[p]].mx, seg[rc[p]].mxl + seg[lc[p]].mxr});
    }
}

void upd(int l,int r,int &p,int pos,bool add){
    if (!p) p = ++idx;
    if (l == r){
        seg[p].mx = seg[p].mxl = seg[p].mxr = (add ^ 1);
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) upd(l, mid, lc[p], pos, add);
    else upd(mid + 1, r, rc[p], pos, add);
    pull(l, r, p);
}
Seg qy(int l,int r,int &p,int ql,int qr){
    if (l >= ql && r <= qr){
        if(!p) return Seg{r - l + 1, r - l + 1, r - l + 1};//不要亂開點OAO
        return seg[p];
    }
    int mid = l + r >> 1;
    if(qr<=mid) return qy(l, mid, lc[p], ql, qr);
    if(ql>mid) return qy(mid + 1, r, rc[p], ql, qr);
    Seg left = qy(l, mid, lc[p], ql, qr), right = qy(mid + 1, r, rc[p], ql, qr), res;
    res.mxl = left.mxl + (left.mxl == mid - l + 1 ? right.mxl : 0);
    res.mxr = right.mxr + (right.mxr == r - mid ? left.mxr : 0);
    res.mx = max({left.mx, right.mx, left.mxr + right.mxl});
    return res;
}

signed main(){shaman;
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        upd(1, n, rt[a[i]], i, 1);
    }
    while (q--){
        int opt;
        cin >> opt;
        if(opt==0){
            int p, k;
            cin >> p >> k;
            p++;
            upd(1, n, rt[a[p]], p, 0);
            a[p] = k;
            upd(1, n, rt[a[p]], p, 1);
        }
        else{
            int x, y, k;
            cin >> x >> y >> k;
            x++;
            cout << qy(1, n, rt[k], x, y).mx << '\n';
        }
    }
}