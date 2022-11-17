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
int f[1000005];
vector<int> match(string a,string b){
    vector<int> ans;
    f[0] = -1, f[1] = 0;
    for (int i = 1, j = 0; i < b.size(); f[++i] = ++j){
        if (b[i] == b[j])
            f[i] = f[j]; //優化
        while (j != -1 && b[i] != b[j])
            j = f[j];
    }
    for (int i = 0, j = 0; i - j + b.size() <= a.size(); ++i, ++j){
        while (j != -1 && a[i] != b[j])
            j = f[j];
        if (j == b.size() - 1)
            ans.pb(i - j), j = f[j];
    }
    return ans;
}