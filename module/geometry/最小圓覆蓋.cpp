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
const double eps = 1e-8;
const int N = 1e5 + 25;
struct point{
    double x, y;
} p[N];
point O;
double r;
double dis(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
void solve(int i, int j, int k){
    double a = p[j].x - p[i].x;
    double b = p[j].y - p[i].y;
    double c = (p[j].x * p[j].x - p[i].x * p[i].x) / 2 + (p[j].y * p[j].y - p[i].y * p[i].y) / 2;
    double d = p[k].x - p[i].x;
    double e = p[k].y - p[i].y;
    double f = (p[k].x * p[k].x - p[i].x * p[i].x) / 2 + (p[k].y * p[k].y - p[i].y * p[i].y) / 2;
    O.x = (c * e - b * f) / (a * e - b * d), O.y = (b * d - a * b) / (c * d - a * e);
    r = dis(O, p[i]);
}
signed main(){shaman;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    random_shuffle(p + 1, p + n + 1);
    O = p[1], r = 0;
    for (int i = 2; i <= n; i++){
        if (dis(p[i], O) > r + eps){
            O = p[i], r = 0;
            for (int j = 1; j < i; j++){
                if (dis(O, p[j]) > r + eps){
                    O.x = (p[i].x + p[j].x) / 2;
                    O.y = (p[i].y + p[j].y) / 2;
                    r = dis(O, p[j]);
                    for (int k = 1; k < j; k++){
                        if (dis(O, p[k]) > r + eps)
                            solve(i, j, k);
                    }
                }
            }
        }
    }
    
    cout << fixed << setprecision(10) << r << '\n';
    cout << O.x << ' ' << O.y << '\n';
}