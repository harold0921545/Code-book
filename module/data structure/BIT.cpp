const int N = 5e5 + 25;
int n, k;
int bit[N];

void upd(int p, int k){
    for (; p < N; p += p & -p)
        bit[p] += k;
}
int kth(int k){
    int cur = 0, res = 0;
    for (int i = __lg(n); ~i; i--){
        res += (1 << i);
        if (res >= n || cur + bit[res] >= k)
            res -= (1 << i);
        else
            cur += bit[res];
    }
    return res + 1;
}
int qy(int p){
    int res = 0;
    for (; p; p -= p & -p)
        res += bit[p];
    return res;
}