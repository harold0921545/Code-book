const int N = 1e6 + 25;
int sa[N], x[N], y[N], cnt[N];
// sa[i] = i-th smallest suffix's index (1-base)
// O(nlogn)
void build_SA(string s){
    int n = s.size(), m = 256;
    for (int i = 1; i <= n; i++)
        x[i] = s[i - 1], cnt[x[i]]++;
    for (int i = 2; i <= m; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n; i; i--)
        sa[cnt[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1){
        int id = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++id] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++id] = sa[i] - k;
        for (int i = 0; i <= m; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++)
            cnt[x[i]]++;
        for (int i = 2; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n; i; i--){
            sa[cnt[x[y[i]]]--] = y[i];
            y[i] = 0;
        }
        swap(x, y);
        id = 1, x[sa[1]] = 1;
        for (int i = 2; i <= n; i++){
            if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                x[sa[i]] = id;
            else
                x[sa[i]] = ++id;
        }
        if (id == n)
            break;
        m = id;
    }
}