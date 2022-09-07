int inv[N];
void linear_inv(int p){
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = (inv[p % i] * (p - p / i)) % p;
}