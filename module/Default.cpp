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

//mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
int read(){
    int res = 0 , f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        res = res * 10 + ch - 48;
        ch = getchar();
    }
    return res * f;
}
void print(int x){
	if(x == 0){
        putchar(48);
        return;
    }
    int len = 0, dg[20];
    while (x > 0){
        dg[++len] = x % 10;
        x /= 10;
    }
    for (int i = len; i >= 1; --i)
        putchar(dg[i] + 48);
}