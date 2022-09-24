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

int cross(pii a, pii b) { return a.F * b.S - a.S * b.F; }
int dis(pii a, pii b){return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);}

signed main(){shaman;
    convex = convexhull();
    if (convex.size() == 2)
        cout << dis(convex[0], convex[1]) << '\n';
    else{
        int j = 2, ans = 0, m = convex.size();
        for (int i = 0; i < convex.size(); i++){
            while (cross({convex[i].F - convex[j].F, convex[i].S - convex[j].S}, {convex[(i + 1) % m].F - convex[j].F, convex[(i + 1) % m].S - convex[j].S}) <= cross({convex[i].F - convex[(j + 1) % m].F, convex[i].S - convex[(j + 1) % m].S}, {convex[(i + 1) % m].F - convex[(j + 1) % m].F, convex[(i + 1) % m].S - convex[(j + 1) % m].S}))
                ans = max(ans, max(dis(convex[i], convex[j]), dis(convex[(i + 1) % m], convex[j]))), (j += 1) %= m;
            ans = max(ans, max(dis(convex[i], convex[j]), dis(convex[(i + 1) % m], convex[j])));
        }
        cout << ans << '\n';
    }
}