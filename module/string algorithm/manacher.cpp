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
signed main() {shaman;
    string tmp, s;
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++){
        s += '*';
        s += tmp[i];
    }
    s += '*';
    vector<int> f(s.size() + 5, 0);
    int l = 0, r = -1, ans = 0;
    for (int i = 0; i < s.size(); i++){
        f[i] = min(r - i + 1, f[r + l - i]);
        while (i - f[i] >= 0 && i + f[i] < s.size() && s[i - f[i]] == s[i + f[i]])
            f[i]++;
        f[i]--;
        if (i + f[i] > r){
            r = i + f[i];
            l = i - f[i];
        }
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
}