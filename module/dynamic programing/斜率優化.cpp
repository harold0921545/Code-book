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
int x[1000005], s[1000005], dp[1000005], a[1000005], b[1000005], dq[1000005];
int ft = 0, bk = -1;
signed main(){shaman;
    int A, B, C, n;
    cin >> n >> A >> B >> C;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
        s[i] = s[i - 1] + x[i];
    }
    /*
        dp[i] = dp[j] + a * s[i] * s[i] - a * 2 * s[i] * s[j] + a * s[j] * s[j] + b * s[i] - b * s[j] + c;
        a[j]= -2 * A * s[j]
        b[j]= dp[j] + A * s[j] * s[j] - b * s[j]
    */
    dq[++bk] = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = -1e18;
        while (ft < bk && a[dq[ft]] * s[i] + b[dq[ft]] < a[dq[ft + 1]] * s[i] + b[dq[ft + 1]])
            ft++;
        dp[i] = a[dq[ft]] * s[i] + b[dq[ft]] + A * s[i] * s[i] + B * s[i] + C;
        a[i] = -2 * A * s[i];
        b[i] = dp[i] + A * s[i] * s[i] - B * s[i];
        while (ft < bk && (a[dq[bk]] - a[dq[bk - 1]]) * (b[dq[bk]] - b[i]) <= (a[i] - a[dq[bk]]) * (b[dq[bk - 1]] - b[dq[bk]]))
            bk--;
        dq[++bk] = i;
    }
    cout << dp[n] << '\n';
}
