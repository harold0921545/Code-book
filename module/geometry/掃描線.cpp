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
struct Node{
    int x, y1, y2, ok;
    bool operator <(const Node &tmp)const{
        return x < tmp.x;
    }
};
const int N = 1e6;
struct Seg{
    int len, sum;
    //點l~點r+1長度
} seg[4000025];
void pull(int l,int r,int rt){
    if (seg[rt].sum > 0) seg[rt].len = r - l + 1;
    else if (r != l) seg[rt].len = seg[ls].len + seg[rs].len;
    else seg[rt].len = 0;
}

void upd(int l,int r,int rt,int ql,int qr,int k){
    if (r + 1 <= ql || l >= qr) return;
    if (l >= ql && r + 1 <= qr){
        seg[rt].sum += k;
        pull(l, r, rt);
        return;
    }
    int mid = l + r >> 1;
    upd(l, mid, ls, ql, qr, k);
    upd(mid + 1, r, rs, ql, qr, k);
    pull(l, r, rt);
}

signed main(){shaman;
    int n;
    cin >> n;
    vector<Node> node;
    for (int i = 0; i < n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        y1++, y2++;
        node.pb({x1, y1, y2, 1});
        node.pb({x2, y1, y2, -1});
    }
    sort(node.begin(), node.end());
    int last = node[0].x;
    long long ans = 0;
    for (int i = 0; i < node.size(); i++){
        ans += 1LL * (node[i].x - last) * seg[1].len;
        upd(1, N + 1, 1, node[i].y1, node[i].y2, node[i].ok);
        last = node[i].x;
    }
    cout << ans << '\n';
}
