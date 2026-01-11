#include<bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map
#define int long long
#define sz(a) (int)a.size()

using namespace std;

string s;
int q, l, r, n;
int cnt[26][100003];
int mx, mn;
int cur[27];
int pos;
int res;
int dis;

void solve(){
    cin >> s >> q;
    n = sz(s);
    foru(i, 0, n - 1){
        for(char c='a'; c<='z'; ++c)    cnt[c - 'a'][i + 1] = cnt[c - 'a'][i];
        cnt[s[i] - 'a'][i + 1] = cnt[s[i] - 'a'][i] + 1;
    }

    while(q--){
        cin >> l >> r;
        mx = 0;
        mn = 26;
        pos = 0;
        res = 0;
        memset(cur, 0, sizeof(cur));

        for(int i=0; i<26; ++i){
            if(cnt[i][r] - cnt[i][l - 1] > 0){
                pos++;
                cur[pos] = i;
            }
        }
        for(int i=1; i<=pos; ++i){
            for(int j=i+1; j<=pos; ++j){
                dis = min(abs(cur[j] - cur[i]), abs(26 - cur[j] + cur[i]));
                res = max(res, dis);
            }
        }
        cout << res;
    }   
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}