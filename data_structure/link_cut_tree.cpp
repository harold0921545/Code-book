#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define debug(x) cerr << #x << " = " << x << '\n'

const int N = 1e5 + 25;

struct LCT{
	int top, c[N][2], fa[N], xr[N], q[N], rev[N], val[N];
	void pull(int x) { xr[x] = xr[c[x][0]] ^ xr[c[x][1]] ^ val[x]; }
	void push(int x){
		if(rev[x]){
			rev[c[x][0]] ^= 1;
			rev[c[x][1]] ^= 1;
			rev[x] = 0;
			swap(c[x][0], c[x][1]);
		}
    }
	bool isroot(int x) { return c[fa[x]][0] != x && c[fa[x]][1] != x; }
	void rotate(int x){
		int y = fa[x], z = fa[y], l, r;
		if (c[y][0] == x)
			l = 0;
		else
			l = 1;
		r = l ^ 1;
		if (!isroot(y)){
			if (c[z][0] == y)
				c[z][0] = x;
			else
				c[z][1] = x;
		}
		fa[x] = z, fa[y] = x, fa[c[x][r]] = y;
		c[y][l] = c[x][r];
		c[x][r] = y;
		pull(y), pull(x);
	}
    void splay(int x){
		top = 1;
		q[top] = x;
		for (int i = x; !isroot(i); i = fa[i])
			q[++top] = fa[i];
		for (int i = top; i; i--)
			push(q[i]);
		while (!isroot(x)){
			int y = fa[x], z = fa[y];
			if (!isroot(y)){
				if ((c[y][0] == x) ^ (c[z][0] == y))
					rotate(x);
				else
					rotate(y);
			}
			rotate(x);
		}
	}
    void access(int x){
		for (int t = 0; x; t = x, x = fa[x])
			splay(x), c[x][1] = t, pull(x);
	}
	void makeroot(int x) { access(x), splay(x), rev[x] ^= 1; }
	int find(int x){
		access(x), splay(x);
		while (c[x][0])
			x = c[x][0];
		return x;
	}
	void split(int x, int y) { makeroot(x), access(y), splay(y); }
	void cut(int x, int y){
		split(x, y);
		if (c[y][0] == x && c[x][1] == 0)
			c[y][0] = 0, fa[x] = 0;
	}
	void link(int x, int y){
		makeroot(x);
		fa[x] = y;
	}
	bool connected(int x, int y) { return find(x) == find(y); }
} lct;


signed main(){
	noTLE;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> lct.val[i];
	while (m--){
		int opt, x, y;
		cin >> opt >> x >> y;
		if (opt == 0){ // xor between x and y
			lct.split(x, y);
			cout << lct.xr[y] << '\n';
		}
		else if (opt == 1){
			if (!lct.connected(x, y))
				lct.link(x, y);
		}
		else if (opt == 2){
			if (lct.connected(x, y))
				lct.cut(x, y);
		}
		else // change value
			lct.access(x), lct.splay(x), lct.val[x] = y, lct.pull(x);
	}
}