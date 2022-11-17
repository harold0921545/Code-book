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
bool a[1005][1005];
int up[1005][1005], r[1005][1005], l[1005][1005];
signed main(){shaman;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j]; 
            up[i][j] = a[i][j];
            l[i][j] = r[i][j] = j;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 2; j <= m; j++)
            if (a[i][j] && a[i][j - 1])
                l[i][j] = l[i][j - 1];
        for (int j = m - 1; j > 0;j--)
            if (a[i][j] && a[i][j + 1])
                r[i][j] = r[i][j + 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] && a[i - 1][j]){
                l[i][j] = max(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }
            ans = max(ans, (r[i][j] - l[i][j] + 1) * up[i][j]);
        }
    }
    cout << ans << '\n';
}