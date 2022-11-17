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
int a[10][10], ans = 0;
vector<pii> v;
void print(){
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cout << a[i][j] << " \n"[j == 8];
}
bool check(int x,int y,int k){
    for (int i = 0; i < 9; i++){
        if (a[x][i] == k)
            return false;
        if (a[i][y] == k)
            return false;
    }
    int nx = (x / 3) * 3, ny = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[nx + i][ny + j] == k)
                return false;
    return true;
}
void solve(int d){
    if (d == v.size()){
        print();
        cout << "\n";
        ans++;
    }
    int x = v[d].F, y = v[d].S;
    for (int i = 1; i <= 9; i++){
        if (check(x, y, i)){
            a[x][y] = i;
            solve(d + 1);
            a[x][y] = 0;
        }
    }
}

signed main(){shaman;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++){
        cin >> a[i][j];
        if (a[i][j] == 0)
            v.pb({i, j});
    }
    solve(0);
    cout << "there are a total of " << ans << " solution(s). ";
}
