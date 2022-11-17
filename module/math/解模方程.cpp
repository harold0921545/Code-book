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
int a[1005][1005];
int n, MOD;
int fpow(int x, int p){
    int r = 1;
    for (; p; p >>= 1){
        if (p & 1)
            (r *= x) %= MOD;
        (x *= x) %= MOD;
    }
    return r;
}
signed main(){shaman;
    cin >> n >> MOD;
    for (int i = 1; i <= n; i++)
        cin >> a[i][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    for (int i = 1; i <= n; i++){
        if (a[i][i] == 0){
            int tmp = i;
            for (int j = i + 1; j <= n; j++)
                if (a[j][i]){
                    tmp = j;
                    break;
                }
            for (int j = 1; j <= n + 1; j++)
                swap(a[i][j], a[tmp][j]);
        }
        int tmp = a[i][i];
        for (int j = i; j <= n + 1; j++)
            (a[i][j] *= fpow(tmp, MOD - 2)) %= MOD;
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            tmp = a[j][i];
            for (int k = 1; k <= n + 1; k++)
                a[j][k] = ((a[j][k] - a[i][k] * tmp % MOD) + MOD) % MOD;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (a[i][n + 1] + MOD) % MOD << ' ';
}