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
const int maxn=2005;
int ans,n,x,tot,cnt,a[maxn+5][maxn+5];
void solve(){
    srand(time(0));
    while(cin >> n,n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        int q;cin >> q;
        while(q--){
            int r1,r2,c1,c2,t=16;
            cin >> r1 >> r2 >> c1 >> c2;
            ans=-1;
            while(t--){
                int rdx=rand()%(r2-r1)+r1,rdy=rand()%(c2-c1)+c1;
                x = a[rdx][rdy];
                tot = cnt = 0;
                for(int i=r1;i<=r2;i++){
                    for(int j=c1;j<=c2;j++){
                        ++tot;
                        if(a[i][j]==x) ++cnt;
                    }
                }
                if(cnt>tot/2){
                    ans=x;
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
}
signed main() {shaman;
    solve();
}
