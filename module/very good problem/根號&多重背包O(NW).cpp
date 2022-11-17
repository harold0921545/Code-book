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
//數字合併
using namespace std;
vector<int> a, b;
int dp[200005],cnt[200005];
deque<int> dq[1000];
signed main(){shaman
    int n, k;
    cin >> n >> k;
    const int K = sqrt(k);
    dp[0] = 1;
    for (int i = 1,x; i <= n; i++){
        cin >> x;
        if (x >= K)
            b.pb(x);
        else{
            if (cnt[x] == 0)
                a.pb(x);
            cnt[x]++;
        }
    }
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[i]; j++){
            dq[j].clear();
            if(dp[j])
                dq[j].pb(j);
        }
        for (int j = a[i]; j <= k; j++){
            int idx = j % a[i];
            while (!dq[idx].empty() && dq[idx].front() + a[i] * cnt[a[i]] < j)
                dq[idx].ppf();
            bool is = dp[j];
            if(!dq[idx].empty())
                dp[j] = 1;
            if(is)
                dq[idx].pb(j);
        }
    }
    for (int i = 0; i < b.size(); i++)
        for (int w = k; w >= b[i]; w--)
            dp[w] |= dp[w - b[i]];
    for (int i = 1; i <= k; i++)
        cout << dp[i];
    cout << '\n';
}
