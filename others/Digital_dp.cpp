int dp[N], a[N]; //dp[]... record everything you want, a[] record the number
//init dp => -1
int dfs(int pos, bool lim, bool zero){ //dfs(pos, mx_number?, leading_zero?, ...)
    if (pos <= 0)
        return ; //something
    if (!lim && !zero && dp[pos] != -1)
        return dp[pos];
    int up = lim ? a[pos] : 1;
    int res = 0;
    for (int i = 0; i <= up; i++)
        res += dfs(pos - 1, lim && (i == up), zero && (i == 0));
    if (!lim && !zero) dp[pos] = res;
    return res;
}

int solve(int now){
    int len = 0;
    for (; now; now /= 10)
        a[++len] = now % 10;
    return dfs(len, 1, 1);
}