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

struct E{
    int to, nxt;
} e[200005];
int e_cnt = 2;
int dfn[100005], low[100005], idx, bcc_cnt, blg[200005], h[100005];
bool vis[200005];
void add(int x, int y){
    e[e_cnt].to = y;
    e[e_cnt].nxt = h[x];
    h[x] = e_cnt++;
}
stack<int> stk;
vector<int> bcc_node[100005], bcc_edge[500005];
void tarjan(int now, int pre){
    dfn[now] = low[now] = ++idx;
    for (int i = h[now]; i; i = e[i].nxt){
        int v = e[i].to;
        if (v == pre || vis[i])
            continue;
        vis[i] = vis[i ^ 1] = 1;
        stk.push(i);
        if (!dfn[v]){
            tarjan(v, now);
            low[now] = min(low[now], low[v]);
            if (low[v] >= dfn[now] && now != pre){
                bcc_cnt++;
                for (int top = -1; top != i; stk.pop()){
                    top = stk.top();
                    if (blg[e[top].to] != bcc_cnt)
                        blg[e[top].to] = bcc_cnt, bcc_node[bcc_cnt].pb(e[top].to);
                    if (blg[e[top ^ 1].to] != bcc_cnt)
                        blg[e[top ^ 1].to] = bcc_cnt, bcc_node[bcc_cnt].pb(e[top ^ 1].to);
                    bcc_edge[bcc_cnt].pb(top);
                    bcc_edge[bcc_cnt].pb(top ^ 1);
                }
            }
        }
        else
            low[now] = min(low[now], dfn[v]);
    }
    //if (now == pre && ch > 0){}
}