const int N;
struct Node{
    int x, y1, y2, ok; //left bound 1, right bound 1
    bool operator <(const Node &tmp)const{
        return x < tmp.x;
    }
} node[N * 2];
struct Seg{
    int len, sum;
} seg[N * 8];
void pull(int l,int r,int rt){
    if (seg[rt].sum > 0) seg[rt].len = r - l + 1;
    else if (r != l) seg[rt].len = seg[ls].len + seg[rs].len;
    else seg[rt].len = 0;
}

void upd(int l,int r,int rt,int ql,int qr,int k){
    if (r + 1 <= ql || l >= qr) return;
    if (l >= ql && r + 1 <= qr){
        seg[rt].sum += k;
        pull(l, r, rt);
        return;
    }
    int mid = l + r >> 1;
    upd(l, mid, ls, ql, qr, k);
    upd(mid + 1, r, rs, ql, qr, k);
    pull(l, r, rt);
}

int rectangles_area(){
    sort(node, node + 2 * n);
    int last = node[0].x;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += 1LL * (node[i].x - last) * seg[1].len;
        upd(1, N + 1, 1, node[i].y1, node[i].y2, node[i].ok);
        last = node[i].x;
    }
    cout << ans << '\n';
}
