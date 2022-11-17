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
mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
const int N = 600005;
vector<int> v[N], scc[N];
int in[N], val[N], dfn[N], low[N], idx, scc_idx, blg[N];
bool instk[N];
stack<int> stk;
void tarjan(int now){
    dfn[now] = low[now] = ++idx;
    stk.push(now);
    instk[now] = true;
    for (auto x : v[now]){
        if (!dfn[x]){
            tarjan(x);
            low[now] = min(low[now], low[x]);
        }
        else if (instk[x])
            low[now] = min(low[now], dfn[x]);
    }
    if (low[now] == dfn[now]){
        scc_idx++;
        for (int top = -1; top != now; stk.pop()){
            top = stk.top();
            blg[top] = scc_idx;
            instk[top] = false;
            s_val[scc_idx] += val[top];
        }
    }
}
