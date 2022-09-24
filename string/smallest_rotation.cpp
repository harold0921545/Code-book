string smallest_rotation(string s) {
    int sz = s.size(), i = 0, j = 1;
    s += s;
    while (i < sz && j < sz) {
        int k = 0;
        while (k < sz && s[i + k] == s[j + k]) k++;
        if (s[i + k] <= s[j + k]) 
            j += k + 1;
        else 
            i += (k + 1);
        if (i == j) 
            j++;
    }
    int ans = i < sz ? i : j;
    return s.substr(ans, sz);
}