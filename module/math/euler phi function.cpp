#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define F first
#define S second
#define int long long
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;
#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"

const int N = 1e6 + 25;
int phi[N];
bitset<N> isp;
vector<int> prime;
signed main(){noTLE;
    isp.set();
    phi[1] = 1;
    for (int i = 2; i < N; i++){
        if (isp[i])
            prime.pb(i), phi[i] = i - 1;
        for (int j = 0; i * prime[j] < N; j++){
            isp[i * prime[j]] = 0;
            if (i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}