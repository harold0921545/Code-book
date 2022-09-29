string s;
char c;
int la, lb, a[100], b[100], res[100];

void add(){
    int cy = 0;
    for(int i = 0; i < max(la, lb); i++){
        res[i] = a[i] + b[i] + cy;
        cy = res[i] / 10;
        res[i] %= 10;
    }
}

void sub(){
    int bw = 0;
    for(int i = 0; i < 100; i++){
        res[i] = a[i] - b[i] - bw;
        if (res[i] < 0)
            bw = 1, res[i] += 10;
        else 
            bw = 0;
    }
}

void mul(){
    memset(res, 0, sizeof(res));
    for (int i = 0; i < la; i++){
        for (int j = 0; j < lb; j++){
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i = 0; i < 100; i++){
        res[i+1] += res[i]/10;
        res[i] %= 10;
    }
}
bool cmp(int x){
    for (int i = lb-1; i >= 0; i--){
        if (a[i+x] < b[i]) return 0;
        if (a[i+x] > b[i]) return 1;
    }
    return 1;
}
void mns(int x){
    for (int i = 0; i < lb; i++)
        a[i+x] -= b[i];
}
void div(){
    memset(res, 0, sizeof(res));
    for (int i = la-lb; i >= 0; i--){
        int cnt = 0;
        while (cmp(i)){
            mns(i);
            cnt++;
        }
        res[i] = cnt;
    }
}
void print(){
    bool flag = false;
    for (int i = 99; i >= 0; i--){
        if (res[i] != 0) flag = true;
        if (flag) cout << res[i];
    }
    if (!flag) cout << 0;
    cout << "\n";
}
 
signed main() {
    string s;
    cin >> s;
    la = s.length();
    memset(a, 0, sizeof(a));
    for (int i = 0; i < la; i++)
        a[la - i - 1] = s[i]-'0';
    cin >> s;
    lb = s.length();
    memset(b, 0, sizeof(b));
    for (int i = 0; i < lb; i++)
        b[lb - i - 1] = s[i] - '0';
}