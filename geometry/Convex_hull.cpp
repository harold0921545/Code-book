vector<pii> convexhull(){
    sort(node.begin(), node.end());
    vector<pii> hull, ans;
    for (int i = 0; i < node.size(); i++){
        while (hull.size() >= 2){
            int sz = hull.size() - 1;
            if (cross({hull[sz].X - hull[sz - 1].X, hull[sz].Y - hull[sz - 1].Y}, {node[i].X - hull[sz - 1].X, node[i].Y - hull[sz - 1].Y}) >= 0)
                hull.pop_back();
            else
                break;
        }
        hull.pb(node[i]);
    }
    ans = hull;
    hull.clear();
    for (int i = 0; i < node.size(); i++){
        while (hull.size() >= 2){
            int sz = hull.size() - 1;
            if (cross({hull[sz].X - hull[sz - 1].X, hull[sz].Y - hull[sz - 1].Y}, {node[i].X - hull[sz - 1].X, node[i].Y - hull[sz - 1].Y}) <= 0)
                hull.pop_back();
            else
                break;
        }
        hull.pb(node[i]);
    }
    for (int i = hull.size() - 2; i >= 0; i--)
        ans.pb(hull[i]);
    int area = 0;
    for (int i = 1; i < ans.size() ; i++)
        area += (cross(ans[i], ans[i - 1]));
    area /= 2;
    return ans;
}
