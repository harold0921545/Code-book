struct Persistent_ST{
    int rt[N * 20], lc[N * 20], rc[N * 20], seg[N * 20], idx;

    void build(int l,int r,int &p, int *data){
        p = ++idx;
        if(l == r){
            seg[p] = data[l];
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, lc[p], data);
        build(mid + 1, r, rc[p], data);
    }

    void upd(int l,int r,int &p,int pre,int q,int k){
        p = ++idx;
        lc[p] = lc[pre], rc[p] = rc[pre], seg[p] = seg[pre];
        if(l == r){
            seg[p] = k;
            return;
        }
        int mid = l + r >> 1;
        if (q <= mid)
            upd(l, mid, lc[p], lc[pre], q, k);
        else
            upd(mid + 1, r, rc[p], rc[pre], q, k);
    }

    int qy(int l,int r,int p,int q){
        if (l == r)
            return seg[p];
        int mid = l + r >> 1;
        if (q <= mid)
            return qy(l, mid, lc[p], q);
        else
            return qy(mid + 1, r, rc[p], q);
    }
};