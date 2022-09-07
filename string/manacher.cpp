int f[N];
int manacher(string tmp){
    string tmp, s;
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++){
        s += '*';
        s += tmp[i];
    }
    s += '*';
    int l = 0, r = -1, ans = 0;
    for (int i = 0; i < s.size(); i++){
        f[i] = min(r - i + 1, f[r + l - i]);
        while (i - f[i] >= 0 && i + f[i] < s.size() && s[i - f[i]] == s[i + f[i]])
            f[i]++;
        f[i]--;
        if (i + f[i] > r){
            r = i + f[i];
            l = i - f[i];
        }
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
}