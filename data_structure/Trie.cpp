int trie[27][N], idx, cnt[N];

void add(string s){
    int u = 0;
    for (int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        if (trie[w][u] == 0)
            trie[w][u] = ++idx;
        u = trie[w][u];
        cnt[u]++;
    }
}

void del(string s){
    int u = 0;
    for (int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        int nxt = trie[w][u];
        cnt[nxt]--;
        if (cnt[nxt] == 0)
            trie[w][u] = 0;
        u = nxt;
    }
}
bool match(string s){
    int u = 0;
    for (int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        if (cnt[trie[w][u]] > 0)
            u = trie[w ^ 1][u];
        else 
            return false;
    }
    return true;
}