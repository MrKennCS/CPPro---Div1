#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
ll res;
map<pair<ll, ll>, int> cnt;
vector<pair<int, int>> a, b;

void solve(){
    cin >> n;

    for(int i=1; i<=n; ++i){
        int u, v;   cin >> u >> v;
        if(i <= n/2)    a.push_back({u, v});
        else            b.push_back({u, v});
    }

    int u, v;   cin >> u >> v;

    for(int mask=0; mask<(1LL<<sz(a)); ++mask){
        pair<ll, ll> sum = {0, 0};
        for(int i=0; i<sz(a); ++i){
            if(get_bit(mask, i) == 1){
                sum.fi += a[i].fi;
                sum.se += a[i].se;
            }
        }
        cnt[{sum.fi, sum.se}]++;
    }

    for(int mask=0; mask<(1LL<<sz(b)); ++mask){
        pair<ll, ll> sum = {0, 0};
        for(int i=0; i<sz(b); ++i){
            if(get_bit(mask, i) == 1){
                sum.fi += b[i].fi;
                sum.se += b[i].se;
            }
        }
        res += cnt[{u - sum.fi, v - sum.se}];
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}