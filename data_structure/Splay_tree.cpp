struct SplayTree {
    int root, tot, fa[N], ch[2][N], val[N], cnt[N], sz[N];
    void maintain(int x) {
        sz[x] = sz[ch[0][x]] + sz[ch[1][x]] + cnt[x];
    }
    bool get(int x) { // x is left(0) or right(1)
        return x == ch[1][fa[x]];
    }
    void clear(int x) {
        ch[0][x] = ch[1][x] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y], chk = get(x);
        ch[chk][y] = ch[chk ^ 1][x];

        if (ch[chk ^ 1][x])
            fa[ch[chk ^ 1][x]] = y;

        ch[chk ^ 1][x] = y;
        fa[y] = x;
        fa[x] = z;

        if (z)
            ch[y == ch[1][z]][z] = x;

        maintain(y);
        maintain(x);
    }
    void splay(int x) { // O(log n)
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f])
                rotate(get(x) == get(f) ? f : x);

        root = x;
    }
    void ins(int x) {
        if (!root) {
            val[++tot] = x;
            cnt[tot]++;
            root = tot;
            maintain(root);
            return;
        }

        int now = root, f = 0;

        while (1) {
            if (val[now] == x) {
                cnt[now]++;
                maintain(now);
                maintain(f);
                splay(now);
                return;
            }

            f = now;
            now = ch[val[now] < x][now];

            if (!now) {
                val[++tot] = x;
                cnt[tot]++;
                fa[tot] = f;
                ch[val[f] < x][f] = tot;
                maintain(tot);
                maintain(f);
                splay(tot);
                return;
            }
        }
    }
    int rk(int x) { // the rank of value x
        int res = 0, now = root;

        while (1) {
            if (x < val[now])
                now = ch[0][now];
            else {
                res += sz[ch[0][now]];

                if (x == val[now]) {
                    splay(now);
                    return res + 1;
                }

                res += cnt[now];
                now = ch[1][now];
            }
        }
    }
    int kth(int k) { // the kth value in splay tree
        int now = root;

        while (1) {
            if (ch[0][now] && k <= sz[ch[0][now]])
                now = ch[0][now];
            else {
                k -= (sz[ch[0][now]] + cnt[now]);

                if (k <= 0) {
                    splay(now);
                    return val[now];
                }

                now = ch[1][now];
            }
        }
    }
    int pre() { // biggest integer smaller than val[root], ins x first and del x later
        int now = ch[0][root];

        if (!now)
            return now;

        while (ch[1][now])
            now = ch[1][now];

        splay(now);
        return now;
    }
    int nxt() { // smallest integer bigger than val[root], same as pre()
        int now = ch[1][root];

        if (!now)
            return now;

        while (ch[0][now])
            now = ch[0][now];

        splay(now);
        return now;
    }
    void del(int x) {
        rk(x); // splay value x to root

        if (cnt[root] > 1) {
            cnt[root]--;
            maintain(root);
            return ;
        }

        if (!ch[0][root] && !ch[1][root]) {
            clear(root);
            root = 0;
            return ;
        }

        if (!ch[0][root]) {
            int now = root;
            root = ch[1][root];
            fa[root] = 0;
            clear(now);
            return ;
        }

        if (!ch[1][root]) {
            int now = root;
            root = ch[0][root];
            fa[root] = 0;
            clear(now);
            return ;
        }

        int now = root, y = pre();
        fa[ch[1][now]] = y;
        ch[1][y] = ch[1][now];
        clear(now);
        maintain(root);
    }
    /*
    merge two splay tree:
        Let roots of two splay tree be x and y
        if x or y is null tree
            return another one
        else
            splay the biggest value x' of x tree to root
            set ch[1][x'] = y
            return x'
    */
};