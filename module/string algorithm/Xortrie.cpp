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
int a[100005], p[100005], mx[100005];
vector<int> v[100005];
int trie[2][6000005], idx, cnt[6000005];

void add(int x){
    int u = 0;
    for (int i = 30; i >= 0; i--){
        bool w = ((x & (1 << i)) > 0);
        if (trie[w][u] == 0)
            trie[w][u] = ++idx;
        u = trie[w][u];
        cnt[u]++;
    }
}

void del(int x){
    int u = 0;
    for (int i = 30; i >= 0; i--){
        bool w = ((x & (1 << i)) > 0);
        int tmp = trie[w][u];
        cnt[tmp]--;
        if (cnt[tmp] == 0)
            trie[w][u] = 0;
        u = tmp;
    }
}
int Find(int x){
    int u = 0, res = 0;
    for (int i = 30; i >= 0; i--){
        bool w = ((x & (1 << i)) > 0);
        if (cnt[trie[w ^ 1][u]] > 0)
            res |= (1 << i), u = trie[w ^ 1][u];
        else
            u = trie[w][u];
    }
    return res;
}