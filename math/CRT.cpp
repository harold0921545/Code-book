int m[N],a[N],mi[N], n;
int CRT(){
    int M = 1, ans =0;
    for(int i = 1; i <= n; i++)
        M *= m[i];
    for(int i = 1; i <= n; i++){
        mi[i] = M / m[i];
        pii tmp = exgcd(mi[i],m[i]);
        int x = tmp.F, y = tmp.S;
        ans += a[i] * mi[i] * (x < 0? x + m[i]: x);
    }
    return ans % M;
}