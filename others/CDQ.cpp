struct node{
    int y, z, id;
};
vector<node> a[N]; // (y, z, time)
bool cmp(node A, node B) { return A.y < B.y; }
int bit[N], ans[N];
int n;
void upd(int p, int k){
    for (int i = p; i < N; i += i & -i)
        bit[i] += k;
}
int qy(int p){
    int res = 0;
    for (int i = p; i; i -= i & -i)
        res += bit[i];
    return res;
}
void solve(int l, int r){
    if (l == r)
        return;
    int mid = l + r >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    vector<node> left, right;
    for (int i = l; i <= mid; i++)
        for (auto x : a[i])
            left.pb(x);
    for (int i = mid + 1; i <= r; i++)
        for (auto x : a[i])
            right.pb(x);
    sort(left.begin(), left.end(), cmp);
    sort(right.begin(), right.end(), cmp);
    for (auto x : right)
        upd(x.z, 1);
    int j = 0;
    for (int i = 0; i < left.size(); i++){
        while (j < right.size() && right[j].y <= left[i].y)
            upd(right[j++].z, -1);
        ans[left[i].id] += (qy(n) - qy(left[i].z));
    }
    for (j; j < right.size(); j++)
        upd(right[j].z,-1);
} 
