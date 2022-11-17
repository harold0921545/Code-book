#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, m;
struct ODT{
    int l, r;
    mutable int v;
    ODT(int L, int R = -1, int V = 0) : l(L), r(R), v(V){};
    bool operator<(const ODT &tmp)const{
        return l < tmp.l;
    }
};
set<ODT> odt;
auto split(int x){
    if (x > n)
        return odt.end();
    auto it = --(odt.upper_bound(ODT(x)));
    if (it->l == x)
        return it;
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert(ODT(l, x - 1, v));
    return odt.insert(ODT(x, r, v)).first;
}

int qy_sum(int l,int r){
    auto itr = split(r + 1), it = split(l);
    int ans = 0;
    for (; it != itr; it++)
        (ans += ((it->r - it->l + 1) * it->v) % MOD) %= MOD;
    return ans % MOD;
}

void modify(int l,int r,int x){
    auto itr = split(r + 1), itl = split(l);
    odt.erase(itl, itr);
    odt.insert(ODT(l, r, x % MOD));
}

void add(int l,int r,int x){
    auto itr = split(r + 1), it = split(l);
    for (; it != itr; it++)
        (it->v += x) %= MOD;
}

void copy(int l,int r,int L,int R){
    vector<ODT> tmp;
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr; it++)
        tmp.push_back(*it);
    auto itR = split(R + 1), itL = split(L);
    odt.erase(itL, itR);
    for(auto i:tmp)
        odt.insert(ODT(i.l - l + L, i.r - l + L, i.v));
}
void exchange(int l,int r,int L,int R){
    if(l>L) swap(l, L), swap(r, R);
    vector<ODT> tmp1, tmp2;
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl; it != itr;it++)
        tmp1.push_back(*it);
    odt.erase(itl, itr);
    auto itR = split(R + 1), itL = split(L);
    for (auto it = itL; it != itR; it++)
        tmp2.push_back(*it);
    odt.erase(itL, itR);
    for(auto i:tmp2)
        odt.insert(ODT(i.l - L + l, i.r - L + l, i.v));
    for(auto i:tmp1)
        odt.insert(ODT(i.l - l + L, i.r - l + L, i.v));
}
void Reverse(int l,int r){
    if (l > r)
        swap(l, r);
    auto itr = split(r + 1), itl = split(l);
    vector<ODT> tmp;
    for (auto it = itl; it != itr; it++) tmp.push_back(*it);
    odt.erase(itl, itr);
    for(auto i:tmp) odt.insert(ODT(r - i.r + l, r - i.l + l, i.v));
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++){
        cin >> x;
        odt.insert(ODT(i, i, x));
    }
    while(m--){
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) //區間和
            cout << qy_sum(l, r) << '\n';
        else if (opt == 2){ //區間改值
            int x;
            cin >> x;
            modify(l, r, x);
        }
        else if (opt == 3){ //區間加值
            int x;
            cin >> x;
            add(l, r, x);
        }
        else if (opt == 4){
            int L, R;
            cin >> L >> R;
            copy(l, r, L, R);
        }
        else if (opt == 5){
            int L, R;
            cin >> L >> R;
            exchange(l, r, L, R);
        }
        else if (opt == 6)
            Reverse(l, r);
    }
    for(auto it:odt){
        for (int i = it.l; i <= it.r;i++)
            cout << it.v << ' ';
    }
    cout << '\n';
}