int a[N][N];
int n, MOD;
void gaussian_elimination_mod(){
    for (int i = 1; i <= n; i++){
        if (a[i][i] == 0){
            int tmp = i;
            for (int j = i + 1; j <= n; j++)
                if (a[j][i]){
                    tmp = j;
                    break;
                }
            for (int j = 1; j <= n + 1; j++)
                swap(a[i][j], a[tmp][j]);
        }
        int tmp = a[i][i];
        for (int j = i; j <= n + 1; j++)
            (a[i][j] *= fpow(tmp, MOD - 2)) %= MOD;
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            tmp = a[j][i];
            for (int k = 1; k <= n + 1; k++)
                a[j][k] = ((a[j][k] - a[i][k] * tmp % MOD) + MOD) % MOD;
        }
    }
    // x_i = a[i][n + 1]
}