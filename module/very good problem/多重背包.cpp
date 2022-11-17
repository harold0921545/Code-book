#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define F first
#define S second
#define mp make_pair
#define debug(x) cerr << #x << " = "  << x << '\n'
#define shaman ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
struct striker{
    int w,m,c;
}a[100005];
int dp[1000005],g[1000005];
int dq[1000005];
signed main(){shaman;
    int n,t;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].w >> a[i].m >> a[i].c;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int k = 0; k < t; k++)
            g[k] = dp[k];
        for (int j = 0; j < a[i].w; j++){
            int ft = 0, bk = -1;
            for (int k = j; k <= t; k += a[i].w){
                if (ft <= bk && dq[ft] < k - a[i].w * a[i].c)
                    ft++;
                if (ft <= bk)
                    dp[k] = max(dp[k], g[dq[ft]] + (k - dq[ft]) / a[i].w * a[i].m);
                while (ft <= bk && g[dq[bk]] - (dq[bk] - j) / a[i].w * a[i].m <= g[k] - (k - j) / a[i].w * a[i].m)
                    bk--;
                dq[++bk] = k;
            }
        }
    }
    cout << dp[t] << '\n';
}
