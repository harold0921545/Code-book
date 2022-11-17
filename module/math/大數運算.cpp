#include <bits/stdc++.h>
using namespace std;
#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"
#define double long double

string operator*(string &a, string &b){
    string res;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() < b.size())
        swap(a, b);
    int num[100] = {}, mx = 0;
    for (int i = 0; i < b.size(); i++){
        int y = b[i] - '0';
        for (int j = 0; j < a.size(); j++){
            int x = a[j] - '0';
            num[j + i] += ((x * y));
            int now = j + i;
            while (num[now] >= 10){
                num[now + 1] += (num[now] / 10);
                num[now] %= 10;
                now++;
            }
            mx = max(mx, now);
        }
    }
    for (int i = 0; i <= mx; i++)
        res += (num[i] + '0');
    reverse(res.begin(), res.end());
    return res;
}
string operator>=(string &a, string &b){
    if (a.size() > b.size())
        return 1;
    if (a.size() == b.size()){
        for (int i = 0; i < a.size(); i++)
            if (a[i] > b[i])
                return 1;
            else if (a[i] < b[i])
                return 0;
        return 1;
    }
    return 0;
}
