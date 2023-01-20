// fail[i] point to the longest prefix == longest suffix of i
const int N = 1e6 + 25;
struct AC_automaton{
    int tr[26][N], fail[N], e[N], idx = 0;
    void clear(){
        for (int i = 0; i <= idx; i++){
            e[i] = fail[i] = 0;
            for (int j = 0; j < 26; j++)
                tr[j][i] = 0;
        }
        idx = 0;
    }
    void ins(string s){
        int now = 0;
        for (int i = 0; i < s.size(); i++){
            if (!tr[s[i] - 'a'][now])
                tr[s[i] - 'a'][now] = ++idx;
            now = tr[s[i] - 'a'][now];
        }
        e[now]++;
    }
    void build(){
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (tr[i][0])
                q.push(tr[i][0]);
        while (!q.empty()){
            int now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++){
                if (tr[i][now]){
                    fail[tr[i][now]] = tr[i][fail[now]];
                    q.push(tr[i][now]);
                }
                else
                    tr[i][now] = tr[i][fail[now]];
            }
        }
    }
    int query(string s){// calculate how many s_i in S
        int now = 0, ans = 0;
        for (int i = 0; i < s.size(); i++){
            now = tr[s[i] - 'a'][now];
            for (int j = now; j && e[j] != -1; j = fail[j])
                ans += e[j], e[j] = -1;
        }
        return ans;
    }
} ac;