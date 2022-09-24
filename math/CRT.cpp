int m[15],a[15],mi[15], n;
pii exgcd(int a, int b){
    if(b == 0) return MP(1, 0);
    else {
        pii tmp = exgcd(b, a % b);
        int t = tmp.F;
        tmp.F = tmp.S, tmp.S = t - tmp.S * (a / b);
        return tmp;
    }
}
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