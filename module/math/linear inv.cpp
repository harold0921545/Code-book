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
int inv[3000005];
signed main(){shaman;
    int n, p;
    cin >> n >> p;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (inv[p % i] * (p - p / i)) % p;
    /*
    assume p = k * i + r
    k = p / i
    r = p % i
    k * i + r = 0 (mod p)
    k * i * (i ^ (-1)) * (r ^ (-1)) + r * (r ^ (-1)) * (i ^ (-1)) = 0 (mod p)
    k * (r ^ (-1)) + i ^ (-1) = 0 (mod p)
    i ^ (-1) = -k * (r ^ (-1)) (mod p)
    i ^ (-1) = -(p / i) * (p % i) ^ (-1)
    */
    for (int i = 1; i <= n; i++)
        cout << inv[i] << "\n";
}