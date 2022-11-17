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
#define shaman ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 1e6;
vector<int> p;
void linear_sieve(){
    for (int i = 0; i < N; i++)
        prime[i] = i;
    for (int i = 2; i < N; i++){
        if (prime[i] == i){
            for (auto x : p){
                if (x * i >= N)
                    break;
                prime[x * i] = x;
                if (i % x == 0)
                    break;
            }
        }
    }
}