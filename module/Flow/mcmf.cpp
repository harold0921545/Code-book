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
const int N = 1005;
int s, t;
int h[N], idx = 2, dis[N], last[N], pre[N], fl[N];
bool vis[N];
struct edge{
    int to, nxt, vl, cost;
} e[2000005];
void add(int u, int v, int val, int c){
    e[idx].to = v;
    e[idx].nxt = h[u];
    e[idx].cost = c;
    e[idx].vl = val;
    h[u] = idx++;
}

bool spfa(){
    fill(dis, dis + t + 1, 1e18);
    fill(fl, fl + t + 1, 1e18);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    pre[s] = -1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int i = h[now]; i; i = e[i].nxt){
            int v = e[i].to, c = e[i].cost;
            if (e[i].vl && dis[v] > dis[now] + c){
                dis[v] = dis[now] + c;
                fl[v] = min(fl[now], e[i].vl);
                pre[v] = now;
                last[v] = i;
                if (!vis[v])
                    q.push(v), vis[v] = 1;
            }
        }
    }
    return dis[t] != 1e18;
}
int ans;
void dinic(){
    while (spfa()){
        int i = t;
        ans += fl[i] * dis[i];
        while (i != s){
            e[last[i]].vl -= fl[t];
            e[last[i] ^ 1].vl += fl[t];
            i = pre[i];
        }
    }
}