int idx, cnt[N];
struct Trie{
    int ch[26];
} tr[N];
void add(string s){
    int u = 0;
    for (int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        if (tr[u].ch[w] == 0)
            tr[u].ch[w] = ++idx;
        u = tr[u].ch[w];
        cnt[u]++;
    }
}
void del(string s){
    int u = 0;
    for (int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        int nxt = tr[u].ch[w];
        cnt[nxt]--;
        if (cnt[nxt] == 0)
            tr[u].ch[w] = 0;
        u = nxt;
    }
}
bool match(string s){
    int u = 0;
    for (int i = 0; i < s.size(); i++){
        int w = s[i] - 'a';
        if (cnt[tr[u].ch[w]] > 0)
            u = tr[u].ch[w];
        else 
            return false;
    }
    return true;
}