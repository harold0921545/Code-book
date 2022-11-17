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

const double eps=1e-9;
const int inf=1e9;
int dp[20000000];
int t,n;

signed main(){shaman
    cin >> t;
    while(t--){
        cin >> n;
        vector <pair<double,double>> v;
        for(int i=1;i<(1<<n);i++)
            dp[i]=inf;
        for(int i=0;i<n;i++){
            double x,y;
            cin >> x >> y;
            v.pb({x,y});
        }
        dp[0]=0;
        int mp[25][25]={};
        set <int> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i].F!=v[j].F){
                    mp[i][j]|=(1<<i)|(1<<j);
                    double A=(v[j].F*v[i].S-v[i].F*v[j].S)/(v[i].F*v[j].F*(v[j].F-v[i].F));
                    double B=(v[i].S*v[j].F*v[j].F-v[j].S*v[i].F*v[i].F)/(v[i].F*v[j].F*(v[j].F-v[i].F));
                    if(A<=0) continue;
                    for(int k=j+1;k<n;k++)
                        if(fabs(((-A)*v[k].F*v[k].F+B*v[k].F)-v[k].S)<eps)
                            mp[i][j]|=(1<<k);
                }
            }
        }
        for(int s=0;s<(1<<n);s++){
            int i;
            if(dp[s]==inf) continue;
            for(i=0;i<n;i++){
                if((s&(1<<i))==0){
                    dp[(s|(1<<i))]=min(dp[(s|(1<<i))],dp[s]+1);
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if((s&(1<<j))==0&&v[i].F!=v[j].F){
                    double A=(v[j].F*v[i].S-v[i].F*v[j].S)/(v[i].F*v[j].F*(v[j].F-v[i].F));
                    if(A<=0) continue;
                    dp[(s|mp[i][j])]=min(dp[(s|mp[i][j])],dp[s]+1);
                }
            }
        }
        cout << dp[(1<<n)-1] << "\n";
    }
}
/*
2
7
1 3
2 4
3 3
2 6
4 8
1 1
1 2
6
1 8
2 12
3 12
4 4
5 5
6 6
*/