int f[N]; // failure function
vector<int> match(string a,string b){
    vector<int> ans;
    f[0] = -1, f[1] = 0;
    for (int i = 1, j = 0; i < b.size(); f[++i] = ++j){
        if (b[i] == b[j])
            f[i] = f[j];
        while (j != -1 && b[i] != b[j])
            j = f[j];
    }
    for (int i = 0, j = 0; i - j + b.size() <= a.size(); ++i, ++j){
        while (j != -1 && a[i] != b[j])
            j = f[j];
        if (j == b.size() - 1)
            ans.pb(i - j), j = f[j];
    }
    return ans;
}