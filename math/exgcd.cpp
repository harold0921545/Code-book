pii exgcd(int a, int b){
    if(b == 0) return MP(1, 0);
    else {
        pii tmp = exgcd(b, a % b);
        int t = tmp.F;
        tmp.F = tmp.S, tmp.S = t - tmp.S * (a / b);
        return tmp;
    }
}