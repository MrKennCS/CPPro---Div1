#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#define get_bit(x, y) (((x) >> (y)) & 1)
#define sz(a) (int)a.size()
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define fi first
#define se second

using namespace std;

int n;
vector<pll> a, b;
map<pll, int> cnt;
int Pow[40];
ll res;

void solve(){
    cin >> n;

    Pow[0] = 1;

    for(int i=1; i<=n; ++i){
        int u, v;
        cin >> u >> v;
        if(i <= n/2)    a.pb({u, v});
        else            b.pb({u, v});

        Pow[i] = Pow[i-1] * 2;

    }

    int u, v;
    cin >> u >> v;

    for(int mask=0; mask<Pow[sz(a)]; ++mask){
        int tmp = mask;
        pll sum = {0, 0};
        for(int i=0; i<sz(a); ++i){
            if(tmp % 2 == 1){
                sum.fi += a[i].fi;
                sum.se += a[i].se;
            }
            tmp /= 2;
        }
        cnt[sum]++;
    }

    for(int mask=0; mask<Pow[sz(b)]; ++mask){
        int tmp = mask;
        pll sum = {0, 0};
        for(int i=0; i<sz(b); ++i){
            if(tmp % 2 == 1){
                sum.fi += b[i].fi;
                sum.se += b[i].se;
            } 
            tmp /= 2;
        }
        res += cnt[{u - sum.fi, v - sum.se}];
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}