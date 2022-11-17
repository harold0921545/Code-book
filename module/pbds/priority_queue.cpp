#include <bits/stdc++.h>
#include <bits/extc++.h>
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
#define shaman ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
//using namespace __gnu_pbds;
const int maxn=1e5+25;
int n,m,ans=0;
vector<int> v[maxn], c(maxn), l(maxn);
__gnu_pbds::priority_queue<int> lan;

void DFS(int now, __gnu_pbds::priority_queue<int> &pq, int &cost){
    pq.push(c[now]);
    cost+=c[now];
    for(auto x:v[now]){
        __gnu_pbds::priority_queue<int> tmp;
        int y=0;
        DFS(x, tmp, y);
        pq.join(tmp);
        cost+=y;
    }
    while(cost>m){
        cost-=pq.top();
        pq.pop();
    }
    if(l[now]*pq.size()>ans) ans=l[now]*pq.size();
}
signed main(){shaman
    cin >> n >> m;
    int st=0,x;
    for(int i=1;i<=n;i++){
        cin >> x >> c[i] >> l[i];
        if(x==0) st=i;
        else v[x].pb(i);
    }
    x = 0;
    DFS(st, lan, x);
    cout << ans << "\n";
}
