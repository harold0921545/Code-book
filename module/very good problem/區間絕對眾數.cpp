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
const int N = 5e5 + 25;
int a[N];
vector<int> v[N];
signed main(){shaman
    int n, q;
    mt19937 mt(time(0));
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        v[a[i]].pb(i);
    }
    while(q--){
        int l, r, t = 22, ans = 0;
        cin >> l >> r;
        while(t--){
            int x = a[l + mt() % (r - l + 1)];
            int ll = 0, rr = v[x].size(), lll = 0, rrr = v[x].size();
            while (ll < rr){
                int mid = ll + rr >> 1;
                if (v[x][mid] > r)
                    rr = mid;
                else
                    ll = mid + 1;
            }
            ll--;
            while (lll < rrr){
                int mid = lll + rrr >> 1;
                if (v[x][mid] >= l)
                    rrr = mid;
                else
                    lll = mid + 1;
            }
            if (ll - lll + 1 > (r - l + 1) / 2){
                ans = x;
                break;
            }
        }
        cout << ans << '\n';
    }
}