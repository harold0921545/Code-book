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

int z[1000005];

signed main(){ noTLE;
    string s;
    cin >> s;
    int l = 0, r = 0;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++){
        z[i] = max(0, min(z[i - l], r - i));
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            l = i, z[i]++, r = i + z[i];
        if (i + z[i] == s.size())
            ans.pb(s.size() - i);
    }
    for (int i = ans.size() - 1; i > 0; i--)
        cout << ans[i] << ' ';
    cout << '\n';
}