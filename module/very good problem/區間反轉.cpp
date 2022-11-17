#include <bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define ls rt<<1
#define rs rt<<1|1
#define debug(x) cerr << #x << " = " << x << "\n"
#define shaman ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
mt19937 mt(time(0));
int val[200005], pri[200005], idx, root, ch[2][200005], f[200005], sz[200005];
int new_nod(int x){
    val[++idx] = x;
    sz[idx] = 1;
    pri[idx] = mt();
    f[idx] = 0;
    return idx;
}
void pull(int x){sz[x] = sz[ch[0][x]] + sz[ch[1][x]] + 1;}
void push(int x){
    swap(ch[0][x], ch[1][x]);
    if (ch[0][x])
        f[ch[0][x]] ^= 1;
    if (ch[1][x])
        f[ch[1][x]] ^= 1;
    f[x] = 0;
}
int Merge(int A, int B){
    if (!A || !B)
        return A | B;
    if (pri[A] > pri[B]){
        if (f[A]) push(A);
        ch[1][A] = Merge(ch[1][A], B);
        pull(A);
        return A;
    }
    else{
        if (f[B]) push(B);
        ch[0][B] = Merge(A, ch[0][B]);
        pull(B);
        return B;
    }
}
void split(int now, int k, int &x, int &y){
    if (!now){
        x = y = 0;
        return;
    }
    if (f[now]) push(now);
    if (sz[ch[0][now]] < k){
        x = now;
        split(ch[1][now], k - sz[ch[0][now]] - 1, ch[1][now], y);
    }
    else{
        y = now;
        split(ch[0][now], k, x, ch[0][now]);
    }
    pull(now);
}
void traverse(int now){
    if (!now)
        return;
    if (f[now]) push(now);
    traverse(ch[0][now]);
    cout << now << ' ';
    traverse(ch[1][now]);
}
signed main(){shaman;
    int n, m;
    while(cin >> n >> m){
        idx = root = 0;
        memset(ch, 0, sizeof(ch));
        for (int i = 1; i <= n; i++)
            root = Merge(root, new_nod(i));
        for (int i = 0; i < m; i++){
            int l, r, x, y, z;
            cin >> l >> r;
            split(root, l - 1, x, y);
            split(y, r - l + 1, y, z);
            f[y] ^= 1;
            root = Merge(x, Merge(y, z));
        }
        traverse(root);
        cout << '\n';
    }
}