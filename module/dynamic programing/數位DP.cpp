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
#define shaman ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
int dp[50][50][50], a[50];
int dfs(int pos, bool lim, bool zero, int sum, int len){
    if (pos <= 0)
        return sum * 2 > len;
    if (!lim && !zero && dp[pos][sum][len] != -1)
        return dp[pos][sum][len];
    int up = lim ? a[pos] : 1;
    int res = 0;
    for (int i = 0; i <= up; i++)
        res += dfs(pos - 1, lim && (i == up), zero && (i == 0), sum + i, len - (zero && (i == 0)));
    if (!lim && !zero) dp[pos][sum][len] = res;
    return res;
}

int solve(int now){
    int len = 0;
    for (; now; now >>= 1)
        a[++len] = now % 2;
    return dfs(len, 1, 1, 0, len);
}

signed main(){shaman;
    int t, m;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--){
        cin >> m;
        cout << solve(m) << "\n";
    }
}
