const int C = 5e5 + 25;
struct Lichaotree{
    struct line{
        int m, k;
        int operator()(const int &x){
            return x * m + k;
        }
    } seg[C << 2];

    #define ls rt << 1
    #define rs rt << 1 | 1
    void build(int l, int r, int rt){
        seg[rt] = {0, (int)1e18};
        if (l == r) return;
        int mid = l + r >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
    }
    void ins(int l, int r, int rt, line L){
        if (l == r){
            if (L(l) < seg[rt](l))
                seg[rt] = L;
            return;
        }
        int mid = l + r >> 1;
        if (seg[rt].m < L.m)
            swap(seg[rt], L);
        if (seg[rt](mid) > L(mid)){
            swap(seg[rt], L);
            ins(l, mid, ls, L);
        }
        else
            ins(mid + 1, r, rs, L);
    }
    int qy(int l, int r, int rt, int x){
        if (l == r)
            return seg[rt](x);
        int mid = l + r >> 1;
        if (x < mid)
            return min(seg[rt](x), qy(l, mid, ls, x));
        return min(seg[rt](x), qy(mid + 1, r, rs, x));
    }
};