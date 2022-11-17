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
constexpr int inf=1e9,MOD=1000000009,N=1e5+87;
int a[N],bit[N],seg[N<<2];
int n,q;
void init_bit(){
    for(int i=1;i<=n;i++)
        bit[i]=a[i]-a[i-(i&-i)];
}
void upd(int p,int k){
    for(;p<N;p+=p&-p)
        bit[p]+=k;
}
int qy(int p){
    int ans=0;
    for(;p;p-=p&-p)
        ans+=bit[p];
    return ans;
}
void seg_bd(){
    for(int i=0;i<n;i++) seg[i+n]=a[i];
    for(int i=n-1;i>0;i--) seg[i]=__gcd(seg[i<<1],seg[i<<1|1]);
}
int sqy(int l,int r){
    int res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) res=__gcd(res,seg[l++]);
        if(r&1) res=__gcd(res,seg[--r]);
    }
    return abs(res);
}

void mdf(int p,int d){
    for(seg[p+=n]+=d;p>1;p>>=1) seg[p>>1]=__gcd(seg[p],seg[p^1]);
}
signed main(){
    //ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    init_bit();
    for(int i=0;i<n;i++)
        a[i]=a[i+1]-a[i];
    seg_bd();
    while(q--){
        int tmp,l,r,k;
        cin >> tmp;
        if(tmp==1){
            cin >> l >> r >> k;
            upd(l,k);
            upd(r+1,-k);
            mdf(l-1,k);
            mdf(r,-k);
        }
        else{
            cin >> l >> r;
            cout << abs(__gcd(qy(r),sqy(l,r))) << "\n";
        }
    }
}
