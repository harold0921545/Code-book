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
int a[100005],lc[100005],rc[100005],dis[100005];
struct seg{
    int l, r, val;
    bool operator >(const seg &tmp)const{
        return val > tmp.val;
    }
    bool operator <(const seg &tmp)const{
        return val < tmp.val;
    }
};

bool u[100005];
signed main(){shaman;
    int n, k, ans = 0;
    cin >> n >> k;
    priority_queue<seg, vector<seg>,greater<seg>> pq;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        u[i] = 0;
        lc[i] = i - 1;
        rc[i] = i + 1;
        if(i>1) pq.push({i - 1, i, a[i] - a[i - 1]}), dis[i] = a[i] - a[i - 1];
    }
    while (!pq.empty() && k > 0){
        int l = pq.top().l, r = pq.top().r, val = pq.top().val;
        pq.pop();
        if (u[l] || u[r]) continue;
        k -= 1;
        u[l] = u[r] = 1;
        ans += val;
        int ll = lc[l], rr = rc[r];
        rc[ll] = rr;
        lc[rr] = ll;
        dis[rr] = dis[rr] + dis[l] - dis[r];
        if (ll >= 1 && rr <= n && !u[ll] && !u[rr])
            pq.push({ll, rr, dis[rr]});
    }
    cout << ans << '\n';
}