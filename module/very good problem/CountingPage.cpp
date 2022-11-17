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
constexpr int inf = 2e9, N = 17, MOD = 1000000007;
int n, k, stp, a[15];
int cnt[15][2][2], dp[15][2][2];
int cnted[15][2][2], dped[15][2][2];
int calc(int pos,bool any,bool st){
    if(pos<0){
        cnt[pos+1][any][st]=st;
        return st;
    }
    if(cnted[pos+1][any][st]==stp) return cnt[pos+1][any][st];
    cnted[pos+1][any][st]=stp;
    auto& ret=cnt[pos+1][any][st];
    ret=0;
    for(int i=0;i<10;i++){
        if(!any &&i>a[pos]) break;
        ret+=calc(pos-1,any||(i<a[pos]),st||i>0);
    }
    return ret;
}
int gg(int pos,bool any,bool st){
    if(pos<0) return 0;
    if(dped[pos][any][st]==stp) return dp[pos][any][st];
    dped[pos][any][st]=stp;
    auto& ret=dp[pos][any][st];
    ret=0;
    for(int i=0;i<10;i++){
        if(!any&&i>a[pos]) break;
        ret+=gg(pos-1,any||i<a[pos],st||i>0)+\
            (i==k)*cnt[pos][any||i<a[pos]][st||i>0]*(i!=0||st);
    }
    return ret;
}
signed main(){shaman
    while(cin >> n >> k){
        stp++;
        int len;
        for(len=0;n>0;len++){
            a[len]=n%10;
            n/=10;
        }
        calc(len,0,0);
        cout << gg(len,0,0) << "\n";
    }
}
