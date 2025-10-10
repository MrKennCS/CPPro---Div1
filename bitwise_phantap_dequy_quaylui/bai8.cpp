#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long
#define sz(a) (int)a.size()
#define pb(val) push_back(val)
#define get_bit(x, y) (((x) >> (y)) & 1)
using namespace std;

int n, x;
vector<int> a, b;
unordered_map<ll, int> cnt;
ll res; 

void solve(){
    cin >> n >> x;
    for(int i=0; i<n; ++i){
        int t;  cin >> t;
        if(i <= n/2)    a.pb(t);
        else            b.pb(t);
    }

    for(int mask=0; mask<(1LL<<sz(a)); ++mask){
        int sum = 0;
        for(int i=0; i<sz(a); ++i){
            if(get_bit(mask, i) == 1)   sum += a[i];
        }
        cnt[sum]++;
    }

    for(int mask=0; mask<(1LL<<sz(b)); ++mask){
        int sum = 0;
        for(int i=0; i<sz(b); ++i){
            if(get_bit(mask, i) == 1){
                sum += b[i];
            }
        }
        res += cnt[x - sum];
    }
    cout << res;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}