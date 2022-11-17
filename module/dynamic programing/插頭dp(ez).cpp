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

const int N = 12;
const ll MOD = 1000000007;
ll dp[2][1 << (N + 1)];
int n, m;

signed main(){noTLE;
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++){
        cin >> n >> m;
        int now = 0, pre = 1;
        fill(dp[0], dp[0] + (1 << m + 1), 0);
        dp[0][0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                swap(now, pre);
                bool pla; cin >> pla;
                fill(dp[now], dp[now] + (1 << m + 1), 0);
                for (int s = 0; s < (1 << m + 1); s++){
                    bool left = (s & (1 << j)), up = (s & (1 << j + 1));
                    if (!pla){
                        if (!left && !up)
                            (dp[now][s] += dp[pre][s]) %= MOD;
                    }
                    else{
                        (dp[now][s ^ (3 << j)] += dp[pre][s]) %= MOD;
                        if (left != up) (dp[now][s] += dp[pre][s]) %= MOD;
                    }
                }
            }
            swap(now, pre);
            fill(dp[now], dp[now] + (1 << m + 1), 0);
            for (int s = 0; s < 1 << m; s++)
                dp[now][s << 1] = dp[pre][s];
        }
        cout << "Case " << cas << ": " << dp[pre][0] << "\n";
    }
}