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
#define matrix vector<vector<int>>
using namespace std;
const int MOD = 1e9 + 7;
matrix operator*(const matrix &a, const matrix &b){
    matrix c = vector<vector<int>>(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++)
                (c[i][j] += a[i][k] * b[k][j]) %= MOD;
    return c;
}
matrix fpow(matrix &a, int p){
    matrix c = {{1, 0}, {0, 1}};
    for (; p; p >>= 1){
        if (p & 1)
            c = c * a;
        a = a * a;
    }
    return c;
}