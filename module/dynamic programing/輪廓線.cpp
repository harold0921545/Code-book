#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;

#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"

const ll MOD = 1e9 + 7;
ll dp[2][2005];
ll n, m;



signed main(){ noTLE;
    cin >> n >> m;
    swap(n, m);
    int now = 0, pre = 1;
    dp[0][(1 << m) - 1] = 1;
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m; j++){
            swap(now, pre);
            fill(dp[now], dp[now] + (1 << m), 0);
            for (int s = 0; s < (1 << m); s++){
                (dp[now][s] += dp[pre][s ^ (1 << j)]) %= MOD;//豎放
                if (j && (s & (1 << j)) && (s & (1 << j - 1)))//橫放
                    (dp[now][s] += dp[pre][s ^ (1 << j - 1)]) %= MOD;
            }
        }
    }
    cout << dp[now][(1 << m) - 1] << '\n';
}