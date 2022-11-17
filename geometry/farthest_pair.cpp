int cross(pii a, pii b) { return a.X * b.Y - a.Y * b.X; }
int dis(pii a, pii b){return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);}

signed main(){
    vector<pii> convex = convexhull();
    if (convex.size() == 2)
        cout << dis(convex[0], convex[1]) << '\n';
    else{
        int j = 2, ans = 0, m = convex.size();
        for (int i = 0; i < convex.size(); i++){
            while (cross({convex[i].X - convex[j].X, convex[i].Y - convex[j].Y}, {convex[(i + 1) % m].X - convex[j].X, convex[(i + 1) % m].Y - convex[j].Y}) <= cross({convex[i].X - convex[(j + 1) % m].X, convex[i].Y - convex[(j + 1) % m].Y}, {convex[(i + 1) % m].X - convex[(j + 1) % m].X, convex[(i + 1) % m].Y - convex[(j + 1) % m].Y}))
                ans = max(ans, max(dis(convex[i], convex[j]), dis(convex[(i + 1) % m], convex[j]))), (j += 1) %= m;
            ans = max(ans, max(dis(convex[i], convex[j]), dis(convex[(i + 1) % m], convex[j])));
        }
        cout << ans << '\n';
    }
}