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
vector <int> v[100005];
int dfn[100005],low[100005],idx=1,vis[100005];
bool ok=true;
bool DFS(int now,int idx){
    dfn[now]=low[now]=idx;
    vis[now]=-1;
    int tmp=0;
    for(auto x:v[now]){
        if(vis[x]==1) return false;
        else if(vis[x]==-1)
            tmp++,low[now]=min(low[now],dfn[x]);
        else {
            if(!DFS(x,idx+1)) return false;
            low[now]=min(low[now],low[x]);
            if(low[x]>dfn[now]) return false;
            if(low[x]<dfn[now]) tmp++;
        }
    }
    vis[now]=1;
    return tmp<2;
}
signed main(){
    int t,n,a,b,m;
    cin >>t;
    while(t--){
        cin >> n >> m;
        ok=true;
        for(int i=0;i<=n;i++)v[i].clear(),dfn[i]=0,low[i]=0,vis[i]=0;
        for(int i=0;i<m;i++){
            cin >> a >>b;
            v[a].pb(b);
        }
        if(!DFS(0,0)) cout << "NO\n";
        else{
            for(int i=0;i<n;i++)
                if(!vis[i]){
                    ok=false;
                    break;
                }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
