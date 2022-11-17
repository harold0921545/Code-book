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
#define shaman ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m;
int a[100005], pos[100005], ans[1000005], tot;
int bit[1000005];
void upd(int p,int k){
    for (int i = p; i <= 100000; i += i & -i)
        bit[i] += k;
}
int qy(int p){
    int r = 0;
    for (; p; p -= p & -p)
        r += bit[p];
    return r;
}
struct CDQ{
    int mm, p, v, ti, id;
} e[1000005];

bool cmp1(CDQ a, CDQ b){return a.p < b.p;}

void cdq(int l, int r){
    if (l == r)
        return;
    int mid = l + r >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(e + l, e + mid + 1, cmp1);
    sort(e + mid + 1, e + r + 1, cmp1);
    int j = l;
    for (int i = mid + 1; i <= r; i++){
        while (j <= mid && e[j].p <= e[i].p)
            upd(e[j].v, e[j].mm), j++;
        ans[e[i].id] += e[i].mm * (qy(n) - qy(e[i].v));
    }
    for (int i = l; i < j; i++)
        upd(e[i].v, -e[i].mm);
    j = mid;
    for (int i = r; i > mid; i--){
        while (j >= l && e[j].p >= e[i].p)
            upd(e[j].v, e[j].mm), j--;
        ans[e[i].id] += e[i].mm * (qy(e[i].v - 1));
    }
    for (int i = mid; i > j; i--)
        upd(e[i].v, -e[i].mm);
}
signed main(){shaman;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
        e[tot++] = {1, i, a[i], 0, 0};
    }
    for (int i = 1, x; i <= m; i++){
        cin >> x;
        e[tot++] = {-1, pos[x], x, i, i};
    }
    cdq(0, tot - 1);
    for (int i = 1; i <= m; i++)
        ans[i] += ans[i - 1];
    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}