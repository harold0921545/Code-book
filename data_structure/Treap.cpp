struct Treap{
    int sz[N], ch[N][2], pri[N], val[N];
    int root, cnt, z, x, y;

    void pull(int rt) { 
        sz[rt] = 1 + sz[ch[rt][0]] + sz[ch[rt][1]]; 
    }
    
    int new_node(int x){
        sz[++cnt] = 1;
        val[cnt] = x;
        pri[cnt] = rand();
        return cnt;
    }

    void split(int now, int k, int &x, int &y){
        if (!now) x = y = 0;
        else{
            if (val[now] <= k)
                x = now, split(ch[now][1], k, ch[now][1], y);
            else
                y = now, split(ch[now][0], k, x, ch[now][0]);
            pull(now);
        }
    }

    int Merge(int A,int B){
        if (!A || !B)
            return A + B;
        if (pri[A] > pri[B]){
            ch[A][1] = Merge(ch[A][1], B);
            pull(A);
            return A;
        }
        else {
            ch[B][0] = Merge(A, ch[B][0]);
            pull(B);
            return B;
        }
    }

    int kth(int now, int k){
        while(1){
            if (k <= sz[ch[now][0]])
                now = ch[now][0];
            else if (k == sz[ch[now][0]] + 1)
                return now;
            else
                k -= sz[ch[now][0]] + 1, now = ch[now][1];
        }
    }
};
