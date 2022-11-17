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
int a[20005],w[20005];
signed main(){shaman
    int n,m;
    int tmp[13]={};
    tmp[0]=1;
    for(int i=1;i<=12;i++){
        tmp[i]=tmp[i-1]*i;
    }
    string s;
    for(int i=0;i<15;i++) s+=(i+'A');
    bitset<13> used;
    while(cin >> n >> m,m+n){
        m-=1;
        m%=tmp[n];
        string ans;
        used.reset();
        for(int i=n-1;i>0;i--){
            int k=-1,u=m/tmp[i];
            m%=tmp[i];
            for(int j=0;j<n;j++){
                if(used[j]) continue;
                k++;
                if(k==u){
                    ans+=s[j];
                    used[j]=1;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(used[i]==0) ans+=s[i];
        }
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
