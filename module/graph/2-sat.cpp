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
#define re register
#define shaman ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
vector<int> v[50];
bool instk[50];
stack<int> stk;
int dfn[50], low[50], idx, blg[50], scc;
void tarjan(int now){
    dfn[now] = low[now] = ++idx;
    instk[now] = 1;
    stk.push(now);
    for (auto x : v[now]){
        if (!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }
        else if (instk[x])
            low[now] = min(low[now], dfn[x]);
    }
    if (dfn[now] == low[now]){
        scc++;
        for (int top = -1; top != now; stk.pop()){
            top = stk.top();
            blg[top] = scc;
            instk[top] = 0;
        }
    }
}
signed main(){shaman;
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        idx = scc = 0;
        for (int i = 1; i <= n; i++)
            v[i].clear(), v[i + n].clear(), dfn[i] = dfn[i + n] = low[i] = low[i + n] = blg[i] = blg[i + n] = 0;
        for (int i = 1; i <= m; i++){
            char a, b;
            int x, y;
            cin >> a >> x >> b >> y;
            if (a == 'm' && b == 'm'){
                v[x + n].pb(y);
                v[y + n].pb(x);
            }
            else if (a == 'm' && b == 'h'){
                v[x + n].pb(y + n);
                v[y].pb(x);
            }
            else if (a == 'h' && b == 'm'){
                v[x].pb(y);
                v[y + n].pb(x + n);
            }
            else{
                v[x].pb(y + n);
                v[y].pb(x + n);
            }
        }
        for (int i = 1; i <= 2 * n; i++)
            if (!dfn[i])
                tarjan(i);
        bool ok = true;
        for (int i = 1; i <= n; i++)
            if (blg[i] == blg[i + n])
                ok = false;
        if (ok)
            cout << "GOOD\n";
        else
            cout << "BAD\n";
    }
}
