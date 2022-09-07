int phi[N];
bool isp[N];
vector<int> prime;
void euler_phi_function(){
    fill(isp, isp + N, 1);
    isp[0] = isp[1] = 0;
    phi[1] = 1;
    for (int i = 2; i < N; i++){
        if (isp[i])
            prime.pb(i), phi[i] = i - 1;
        for (int j = 0; i * prime[j] < N; j++){
            isp[i * prime[j]] = 0;
            if (i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
}