struct Sparse_table{
    int st[__lg(N) + 1][N]; // st[i][j] => [j, j+(1<<i))

    void bd_st(int n, int *data){
        for (int i = 1; i <= n; i++)
            st[0][i] = data[i];
        for (int i = 1; (1 << i) <= n; i++)
            for (int j = 1; j + (1 << i) <= n + 1; j++)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }
    int qy(int l, int r){
        int len = __lg(r - l + 1);
        return max(st[len][l], st[len][r - (1 << len) + 1]);
    }
};