struct query{
    int l, r, id, bid;
    bool operator<(const query& tmp) const{ return bid < tmp.bid || (bid == tmp.bid && r < tmp.r) ;}
};
void add(int x){
    //do something
}

void sub(int x){
    //do something
}
signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<query> Q;
    int k = sqrt(n);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        Q.pb({l, r, i, l / k});
    }
    int l = 0, r = -1;
    for(int i = 0; i < q; i++){
        while(l < Q[i].l) sub(a[l++]);
        while(l > Q[i].l) add(a[--l]);
        while(r < Q[i].r) add(a[++r]);
        while(r > Q[i].r) sub(a[r--]);
        ans[Q[i].id] = // answer
    }
}