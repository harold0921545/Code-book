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
#define shaman ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = 1e5 + 25;
int sz[maxn], ch[maxn][2], fix[maxn], val[maxn];
void pull(int rt) { sz[rt] = 1 + sz[ch[rt][0]] + sz[ch[rt][1]]; }
int root, cnt, z, x, y;

int new_node(int x){
    sz[++cnt] = 1;
    val[cnt] = x;
    fix[cnt] = rand();
    return cnt;
}

void split(int now, int k, int &x, int &y){
    if (!now) x = y = 0;
    else{
        if (val[now] <= k)
            x = now, split(ch[now][1], k, ch[now][1], y);
        else
            y = now, split(ch[now][0], k, x, ch[now][0]);
        pull(now);
    }
}

int Merge(int A,int B){
    if (!A || !B)
        return A + B;
    if (fix[A] > fix[B]){
        ch[A][1] = Merge(ch[A][1], B);
        pull(A);
        return A;
    }
    else {
        ch[B][0] = Merge(A, ch[B][0]);
        pull(B);
        return B;
    }
}

int kth(int now, int k){
    while(1){
        if (k <= sz[ch[now][0]])
            now = ch[now][0];
        else if (k == sz[ch[now][0]] + 1)
            return now;
        else
            k -= sz[ch[now][0]] + 1, now = ch[now][1];
    }
}

signed main(){shaman;
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--){
        int opt, a;
        cin >> opt >> a;
        if (opt == 1){
            split(root, a - 1, x, y);
            root = Merge(Merge(x, new_node(a)), y);
        }
        else if (opt == 2){
            split(root, a, x, z);
            split(x, a - 1, x, y);
            y = Merge(ch[y][0], ch[y][1]);
            root = Merge(Merge(x, y), z);
        }
        else if (opt == 3){
            split(root, a - 1, x, y);
            cout << sz[x] + 1 << "\n";
            root = Merge(x, y);
        }
        else if (opt == 4)
            cout << val[kth(root, a)] << "\n";
        else if (opt == 5){
            split(root, a - 1, x, y);
            cout << val[kth(x, sz[x])] << "\n";
            root = Merge(x, y);
        }
        else if (opt == 6){
            split(root, a, x, y);
            cout << val[kth(y, 1)] << "\n";
            root = Merge(x, y);
        }
    }
}