const double eps = 1e-8;
const int N = 5;
pdd p[N], O;
double r;
double dis(pdd a, pdd b) { return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y)); }
void solve(int i, int j, int k){
    double a = p[j].X - p[i].X;
    double b = p[j].Y - p[i].Y;
    double c = (p[j].X * p[j].X - p[i].X * p[i].X) / 2 + (p[j].Y * p[j].Y - p[i].Y * p[i].Y) / 2;
    double d = p[k].X - p[i].X;
    double e = p[k].Y - p[i].Y;
    double f = (p[k].X * p[k].X - p[i].X * p[i].X) / 2 + (p[k].Y * p[k].Y - p[i].Y * p[i].Y) / 2;
    O.X = (c * e - b * f) / (a * e - b * d), O.Y = (b * d - a * b) / (c * d - a * e);
    r = dis(O, p[i]);
}
pair<pii, int> smallest_enclosing_circle(){
    random_shuffle(p + 1, p + n + 1);
    O = p[1], r = 0;
    for (int i = 2; i <= n; i++){
        if (dis(p[i], O) > r + eps){
            O = p[i], r = 0;
            for (int j = 1; j < i; j++){
                if (dis(O, p[j]) > r + eps){
                    O.X = (p[i].X + p[j].X) / 2;
                    O.Y = (p[i].Y + p[j].Y) / 2;
                    r = dis(O, p[j]);
                    for (int k = 1; k < j; k++){
                        if (dis(O, p[k]) > r + eps)
                            solve(i, j, k);
                    }
                }
            }
        }
    }
    return MP(O, r);
}