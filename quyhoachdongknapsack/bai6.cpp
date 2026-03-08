// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define ull unsigned long long
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define ii pair<int, int>
#define getbit(x, y) (((x) >> (y)) & 1)
#define turnon(x, y) ((x) | (1LL << y))
#define turnof(x, y) ((x) ^ (1LL << y))
#define foru(i, a, b)   for(int i=a; i<=b; ++i)
#define ford(i, a, b)   for(int i=a; i>=b; --i)
#define foruc(i, a, b, c)   for(int i=a; i<=b; i+=c)
#define fordc(i, a, b, c)   for(int i=a; i>=b; i-=c)

#define fi first
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define lb lower_bound // >=
#define ub upper_bound // >

const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n, m;
int dp[100005];
vector<ii> vec;
vector<ii> W[2005];
int num;
int check;
int lay;
int res;

void solve(){
    cin >> m >> n;
    // nhap vao
    for(int i=1; i<=n; ++i){
        int v, w, k;    cin >> v >> w >> k;
        W[w].pb({v, k});
    }
    // xu ly input
    for(int i=1; i<=m; ++i){

        if(W[i].empty())    continue;
        // lay s / w phan tu dau tien
        
        sort(W[i].begin(), W[i].end(), greater<ii>());

        num = m / i;    // so luong toi da duoc lay
        check = 0;      // so luong da lay

        if(check == num)    break;  // added

        for(int j=0; j<sz(W[i]); ++j){

            int v = W[i][j].fi;
            int k = W[i][j].se;

            lay = min(k, num - check);

            for(int cnt=0; cnt<lay; cnt++){
                vec.pb({i, v});
            }

            check += lay;
        }
    }

    // in ra input truoc khi loc
    /*
    cout << "TRUOC LOC \n";
    for(int i=1; i<=m; ++i){
        if(W[i].empty()) continue;

        for(int j=0; j<sz(W[i]); ++j){
            cout << i << " " << W[i][j].fi << " " << W[i][j].se << '\n';
        }
    }
    cout << '\n';
    */

    // in ra vec sau loc
    /*
    cout << "SAU LOC \n";
    for(int i=0; i<sz(vec); ++i){
        cout << vec[i].fi << " " << vec[i].se << '\n';
    }
    */

    /*
    for(int i=1; i<=m; ++i){
        // W[i]
        sort(W[i].begin(), W[i].end(), greater<ii>());
        if(W[i].empty())   continue;
        for(int j=0; j<sz(W[i]); ++j){
            cout << i << " " << W[i][j].fi << " " << W[i][j].se << '\n';
        }
    }
    */

    // input -> output
    //cout << "INP -> OUT\n";
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;

    for(int i=0; i<sz(vec); ++i){
        for(int j=m; j>=vec[i].fi; j--){
            //if(dp[j - vec[i].fi] + vec[i].se > dp[i])   dp[i] = dp[j - vec[i].fi] + vec[i].se;
            dp[j] = max(dp[j], dp[j - vec[i].fi] + vec[i].se);
        }
    }
    /*
    */
    for(int i=0; i<=m; ++i){
        res = max(res, dp[i]);
        //cout << dp[i] << " ";
    }
    //cout << '\n';

    cout << res;
    /*
    */

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
