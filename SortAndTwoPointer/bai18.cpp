#include<iostream>
#include<vector>
#define sz(a) (int)a.size()
using namespace std;

int q, k;
string s;
long long res;
vector<int> cnt(30, 0);

void solve(){
    cin >> s >> k;
    int n = sz(s);
    s = " " + s;
    
    //cout << s << '\n';
    
    cnt = vector<int>(30, 0);
    res = 0;

    /*
    1
    abcaabbc
    2

    a       1
    ab      2
    abc     3
    abca    4
    bcaa    4
    bcaab   5
    caabb   5
    caabbc  6
    */

    int l=1;
    for(int r=1; r<=n; ++r){
        cnt[s[r] - 'a'] += 1;

        while(l+1 <= r && cnt[s[r] - 'a'] > k){
            cnt[s[l] - 'a'] -= 1;
            l += 1;
        }
        //cout << l << " " << r << '\n';
        /*
        cnt[s[l] - 'a'] -= 1;
        l += 1;
        */

        res += (1LL * r - l + 1);
    }
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}