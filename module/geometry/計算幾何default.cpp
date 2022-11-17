const double eps = 1e-6;
#define X first
#define Y second
pdd operator+(pdd a, pdd b){
    return pdd(a.X + b.X, a.Y + b.Y);
}
pdd operator-(pdd a, pdd b){
    return pdd(a.X - b.X, a.Y - b.Y);
}
pdd operator*(pdd a, double b){
    return pdd(a.X * b, a.Y * b);
}
pdd operator/(pdd a, double b){
    return pdd(a.X / b, a.Y / b);
}
double dot(pdd a, pdd b){
    return a.X * b.X + a.Y * b.Y;
}
double cross(pdd a, pdd b){
    return a.X * b.Y - a.Y * b.X;
}
double abs2(pdd a){
    return dot(a, a);
}
double abs(pdd a){
    return sqrt(dot(a, a));
}
int sign(double a){
    return fabs(a) < eps ? 0 : a > 0 ? 1 : -1;
}
int ori(pdd a, pdd b, pdd c){
    return sign(cross(b - a, c - a));
}
bool btw(pdd a, pdd b, pdd c){
    if (sign(ori(a, b, c)) != 0)
        return 0;
    return sign(dot(a - c, b - c)) <= 0;
}
bool seg_intersection(pdd a, pdd b, pdd c, pdd d){
    int a123 = ori(a, b, c);
    int a124 = ori(a, b, d);
    int a341 = ori(c, d, a);
    int a342 = ori(c, d, b);
    if (!a123 && !a124)
        return btw(a, b, c) || btw(a, b, d) || btw(c, d, a) || btw(c, d, b);
    return a123 * a124 <= 0 && a341 * a342 <= 0;
}