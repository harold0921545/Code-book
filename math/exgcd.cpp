pii exgcd(int a, int b){
    if(b == 0) return MP(1, 0);
    else {
        pii tmp = exgcd(b, a % b);
        int z = tmp.F;
        tmp.F = tmp.S, tmp.S = z - tmp.S * (a / b);
        return tmp;
    }
}