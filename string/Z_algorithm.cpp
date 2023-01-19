//z[i] = longest common prefix(s[0~z[i]] == s[i~i+z[i]])
//match: let s = a + b, calculate Z value of s
int z[N];
vector<int> Z_val(string s){
    int l = 0, r = 0;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++){
        z[i] = max(0, min(z[i - l], r - i));
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            l = i, z[i]++, r = i + z[i];
        if (i + z[i] == s.size())
            ans.pb(s.size() - i);
    }
    return ans;
}
