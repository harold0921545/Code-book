//maximmum xor
int bas[50];
void ins(int x){
    for (int i = 20; i >= 0; i--){
        if ((x >> i) & 1){
            if (!bas[i])
                bas[i] = x;
            x ^= bas[i];
        }
    }
}
int q_mx(){
    int r = 0;
    for (int i = 20; i >= 0; i--){
        if ((r ^ bas[i]) > r)
            r ^= bas[i];
    }
    return r;
}
