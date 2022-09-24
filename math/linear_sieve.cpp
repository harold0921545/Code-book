bool prime[N];
vector<int> p;
void linear_sieve(){
    for (int i = 0; i < N; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; i++){
        if (prime[i]) 
            p.pb(i);
        for (auto x : p){
            if (x * i >= N)
                break;
            prime[x * i] = 0;
            if (i % x == 0)
                break;
        }
        
    }
}