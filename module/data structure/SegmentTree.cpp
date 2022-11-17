struct SegmentTree{
    int seg[N * 4],lazy[N * 4];

    #define ls rt << 1
    #define rs rt << 1 | 1
    
    void pull(int rt){
        //seg[rt] = seg[ls] + seg[rs];
    }
    void push(int l,int r,int rt){
        if (l == r || lazy[rt] == 0)
            return;
        //
    }
    void build(int l, int r, int rt, int *data){
        if (l == r){
            seg[rt] = data[l];
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, ls, data);
        build(mid + 1, r, rs, data);
        pull(rt);
    }
    void upd(int l, int r, int rt, int ql, int qr, int k){
        if (l >= ql && r <= qr){
            //seg[rt]
            return;
        }
        push(l, r, rt);
        int mid = l + r >> 1;
        if (ql <= mid)
            upd(l, mid, ls, ql, qr, k);
        if (qr > mid)
            upd(mid + 1, r, rs, ql, qr, k);
        pull(rt);
    }
    int qy(int l,int r, int rt, int ql, int qr){
        if (l >= ql && r <= qr)
            return seg[rt];
        push(l, r, rt);
        int mid = l + r >> 1;
        if (qr <= mid)
            return qy(l, mid, ls, ql, qr);
        if (ql > mid)
            return qy(mid + 1, r, rs, ql, qr);
        return qy(l, mid, ls, ql, qr) + qy(mid + 1, r, rs, ql, qr);
    }
};