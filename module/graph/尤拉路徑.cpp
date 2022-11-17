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
multiset <int> v[505];
vector <int> ans;
void DFS(int now){
    while(v[now].size()){
        int a=*v[now].begin();
        v[now].erase(v[now].find(a));
        v[a].erase(v[a].find(now));
        DFS(a);
    }
    ans.pb(now);
}
signed main() {
    shaman
    int m;
    while(cin >> m,m){
        int x,y;
        ans.clear();
        for(int i=0;i<m;i++){
            cin >> x >> y;
            v[x].insert(y);
            v[y].insert(x);
        }
        int st = 1;
        for(int i=1;i<=500;i++){
            if (v[i].size() % 2 == 1){
                st=i;
                break;
            }
        }
        DFS(st);
        reverse(ans.begin(), ans.end());
        for (int i : ans)
            cout << i << "\n";
        cout << "\n";
    }
}
