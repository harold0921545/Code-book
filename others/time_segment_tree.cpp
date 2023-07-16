const int N = 1e5 + 25;
int ans;
int f[N], sz[N], res[N];
map<pii, int> mp;
vector<pii> seg[N << 2];
stack<pii> ud_sz, ud_f;
#define ls rt << 1
#define rs rt << 1 | 1
 
int Find(int x){
	return f[x] == x ? x : Find(f[x]);
}
bool uni(int a, int b){
	int p = Find(a), q = Find(b);
	if (p == q)
		return 0;
	if (sz[p] < sz[q])
		swap(p, q);
	ud_sz.push(MP(p, sz[p]));
	ud_f.push(MP(q, f[q]));
	ans--;
 
	sz[p] += sz[q];
	f[q] = p;
	return 1;
}
void upd(int rt, int l, int r, int ql, int qr, pii edg){
	if (l >= ql && r <= qr){
		seg[rt].pb(edg);
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid)
		upd(ls, l, mid, ql, qr, edg);
	if (qr > mid)
		upd(rs, mid + 1, r, ql, qr, edg);
}
void traversal(int rt, int l, int r){
	int cnt = 0;
	for (auto i : seg[rt]){
		if (uni(i.F, i.S))
			cnt++;
	}
 
	if (l == r)
		res[l] = ans;
	else{
		int mid = l + r >> 1;
		traversal(ls, l, mid);
		traversal(rs, mid + 1, r);
 
	}
	while (cnt--){
		pii x = ud_sz.top(), y = ud_f.top();
		ud_sz.pop();
		ud_f.pop();
		sz[x.F] = x.S;
		f[y.F] = y.S;
		ans++;
	}
}
signed main(){
	noTLE;
	int n, m, k;
	cin >> n >> m >> k;
	ans = n;
	for (int i = 1; i <= n; ++i)
		f[i] = i, sz[i] = 1;
	for (int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		mp[MP(a, b)] = 0;
	}
	for (int i = 1; i <= k; ++i){
		int t, a, b;
		cin >> t >> a >> b;
		if (a > b)
			swap(a, b);
		if (t == 1)
			mp[MP(a, b)] = i;
		else{
			upd(1, 0, k, mp[MP(a, b)], i - 1, MP(a, b));
			mp.erase(mp.find(MP(a, b)));
		}
	}
	for (auto i : mp)
		upd(1, 0, k, i.S, k, i.F);
	traversal(1, 0, k);
	for (int i = 0; i <= k; ++i)
		cout << res[i] << ' ';
	cout << '\n';
}
 