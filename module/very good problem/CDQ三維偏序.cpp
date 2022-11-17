#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
struct node{
    int y, z, id;
};
vector<node> a[100005];
bool cmp(node A, node B) { return A.y < B.y; }
int bit[100005], ans[100005];
int n;
void upd(int p, int k){
    for (int i = p; i<=100000; i += i & -i)
        bit[i] += k;
}
int qy(int p){
    int res = 0;
    for (int i = p; i; i -= i & -i)
        res += bit[i];
    return res;
}
void solve(int l, int r){
    if (l == r)
        return;
    int mid = l + r >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    vector<node> left, right;
    for (int i = l; i <= mid; i++)
        for (auto x : a[i])
            left.pb(x);
    for (int i = mid + 1; i <= r; i++)
        for (auto x : a[i])
            right.pb(x);
    sort(left.begin(), left.end(), cmp);
    sort(right.begin(), right.end(), cmp);
    for (auto x : right)
        upd(x.z, 1);
    int j = 0;
    for (int i = 0; i < left.size(); i++){
        while (j < right.size() && right[j].y <= left[i].y)
            upd(right[j++].z, -1);
        ans[left[i].id] += (qy(n) - qy(left[i].z));
    }
    for (j; j < right.size(); j++)
        upd(right[j].z,-1);
} 

signed main(){shaman;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x].pb({y, z, i});
    }
    solve(1, n);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}