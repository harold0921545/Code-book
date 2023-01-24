// res % m[i] == r[i]
int CRT(int n, int *m, int *r){
    int M = 1, res = 0;
    for (int i = 1; i <= n; i++)
        M *= m[i];
    for (int i = 1; i <= n; i++){
        int tm = M / m[i], x, y;
        exgcd(tm, m[i], x, y);
        res = ((res + r[i] * tm * x % M)) % M;
    }
    return (res + M) % M;
}