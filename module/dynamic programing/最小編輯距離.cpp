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
int dp[1005][1005];
signed main(){shaman;
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<=a.size();i++) dp[i][0]=i;
    for(int i=0;i<=b.size();i++) dp[0][i]=i;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }
    cout << dp[a.size()][b.size()] << "\n";
}
