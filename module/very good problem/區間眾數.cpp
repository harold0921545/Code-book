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
int a[100005],n,k,m,c[100005],mx,cnt[100005],ans[100005];
struct query{
    int l,r,id,bid;
    bool operator<(const query& tmp)const{return bid<tmp.bid||(bid==tmp.bid&&r<tmp.r);}
}qu[1000005];
void add(int x){
    cnt[x]++;
    c[cnt[x]]++;
    c[cnt[x]-1]--;
    mx=max(mx,cnt[x]);
}

void sub(int x){
    cnt[x]--;
    c[cnt[x]]++;
    c[cnt[x]+1]--;
    while(c[mx]<=0) c[mx]=0,mx--;
}
signed main(){shaman
    cin >> n >> m;
    k=sqrt(n);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        cin >> qu[i].l >> qu[i].r;
        qu[i].id=i;
        qu[i].bid=qu[i].l/k;
    }
    sort(qu,qu+m);
    int l=0,r=-1;
    for(int i=0;i<m;i++){
        while(l<qu[i].l) sub(a[l++]);
        while(l>qu[i].l) add(a[--l]);
        while(r<qu[i].r) add(a[++r]);
        while(r>qu[i].r) sub(a[r--]);
        ans[qu[i].id]=mx;
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << "\n";
    }
}
