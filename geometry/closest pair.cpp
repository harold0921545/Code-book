vector<pii> v;
double dis(int a, int b) { return sqrt((double)(v[a].F - v[b].F) * (v[a].F - v[b].F) + (double)(v[a].S - v[b].S) * (v[a].S - v[b].S)); }
bool cmpbyX(pii a, pii b) { return a.F < b.F || (a.F == b.F && a.S < b.S); }
bool cmpbyY(int a, int b) { return v[a].S < v[b].S || (v[a].S == v[b].S && v[a].F < v[b].F); }
double solve(int l,int r){
    double d = 1 << 30;
    if (l == r)
        return d;
    if (l + 1 == r)
        return dis(l, r);
    int mid = l + r >> 1;
    double d1 = solve(l, mid);
    double d2 = solve(mid + 1, r);
    d = min(d1, d2);
    vector<int> tmp;
    for (int i = l; i <= r; i++)
        if (abs(v[i].F - v[mid].F) <= d)
            tmp.pb(i);
    sort(tmp.begin(), tmp.end(), cmpbyY);
    for (int i = 0; i < tmp.size(); i++)
        for (int j = i + 1; j < tmp.size() && v[tmp[j]].S - v[tmp[i]].S < d; j++)
            d = min(d, dis(tmp[i], tmp[j]));
    return d;
}