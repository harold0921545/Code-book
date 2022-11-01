// n < 2^32 {2, 7, 61}
// n < 2^64 {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
using ll = long long;
ll mult(ll a, ll b, ll m){
    return ((a % m) * (b % m)) % m;
}
ll fpow(ll a, ll b, ll m){
    ll r = 1;
    a %= m;
    for(;; b >>= 1){
        if(b & 1)
            (r *= a) %= m;
        (a *= a) %= m;
    }
    return r;
}
bool miller_rabin(ll a, ll n){
    if(n < 2) 
        return true;
    if(n % 2 == 0)
        return n != 2;
    a %= n;
    if(!a)
        return false;
    ll u = n - 1;
    int t = 0;
    while(!(u % 2)){
        u /= 2;
        t++;
    }
    ll x = fpow(a, u, n);
    for(int i = 0; i < t; i++){
        ll nx = mult(x, x, n);
        if(nx == 1 && x != 1 && x != n - 1)
            return true;
        x = nx;
    }
    return x != 1;
}