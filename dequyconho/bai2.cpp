#include<iostream>
#include<vector>
#include<unordered_map>
#define sz(a)
#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

int n, m;
vector<ii> a, b;
unordered_map<int, int> cnt;
int res;
int id;

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; ++i){
        ii tmp; cin >> tmp.fi >> tmp.se;
        if(i <= n/2)    a.pb(tmp);
        else            b.pb(tmp);
    }

    for(int mask=0; mask<(1LL<<sz(a)); ++mask){
        ii sum = {0, 0};
        for(int i=0; i<sz(a); ++i){
            if(get_bit(mask, i) == 1){
                sum.fi += a[i].fi;
                sum.se += a[i].se;
            }
        }
        if(sum.fi <= m) res = max(res, sum.se);
        cnt[sum.fi] = sum.se;
        /*
        cnt[id] = sum;
        id++;
        */
    }

    for(int mask=0; mask<(1LL<<sz(b)); ++mask){
        ii sum = {0, 0};
        for(int i=0; i<sz(b); ++i){
            if(get_bit(mask, i) == 1){
                sum.fi += b[i].fi;
                sum.se += b[i].se;
            }
        }
        if(sum.fi <= m) res = max(res, sum.se);
        for(unordered_map<int, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it){
            if(sum.fi + (*it).fi <= m)    res = max(sum.se + (*it).se, res);
        }

    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}