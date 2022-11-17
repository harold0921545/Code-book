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
int idx = 2, h[505], lev[505];
struct edge{
    int to, nxt, val;
}e[100005];
int n, m, ed, st;
void add(int u,int v,int vl){
    e[idx].to = v;
    e[idx].nxt = h[u];
    e[idx].val = vl;
    h[u] = idx++;
}
bool bfs(){
    memset(lev, -1, sizeof(lev));
    queue<int> q;
    q.push(st);
    lev[st] = 1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = h[now]; i != 0; i = e[i].nxt){
            int x = e[i].to, vl = e[i].val;
            if (vl && lev[x] == -1){
                lev[x] = lev[now] + 1;
                q.push(x);
            }
        }
    }
    return lev[ed] != -1;
}
int dfs(int now, int in){
    if (now == ed)
        return in;
    int out = 0;
    for (int i = h[now]; i != 0; i = e[i].nxt){
        int x = e[i].to, vl = e[i].val;
        if (vl && lev[x] == lev[now] + 1){
            int tmp = dfs(x, min(vl, in));
            e[i].val -= tmp;
            e[i ^ 1].val += tmp;
            in -= tmp;
            out += tmp;
        }
    }
    if (out == 0) lev[now] = -1;
    return out;
} 
int dinic(){
    int res = 0;
    while(bfs())
        res += dfs(st, 1e18);
    return res;
}
