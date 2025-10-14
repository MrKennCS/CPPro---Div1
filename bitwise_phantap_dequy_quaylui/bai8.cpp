#include<iostream>
#include<vector>
#include<bitset>
#include<unordered_map>
#define pb push_back
#define ll long long
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)
using namespace std;

int n, x;
vector<int> a, b;
unordered_map<ll, int> cnt;
ll Pow[50];
ll sum;
ll res;

void solve(){
    cin >> n >> x;
    
    Pow[0] = 1;
    for(int i=1; i<=n; ++i){
        int t;  cin >> t;
        if(i <= n/2)    a.pb(t);
        else            b.pb(t);
        Pow[i] = Pow[i-1] * 2;
    }

    for(int mask=0; mask<Pow[sz(a)]; ++mask){
        int tmp = mask;
        sum = 0;
        for(int i=0; i<sz(a); ++i){
            if(tmp % 2 == 1){
                sum += a[i];
            }
            tmp /= 2;
        }
        cnt[sum]++;
    }

    for(int mask=0; mask<Pow[sz(b)]; ++mask){
        int tmp = mask;
        sum = 0;
        for(int i=0; i<sz(b); ++i){
            if(tmp % 2 == 1){
                sum += b[i];
            }
            tmp /= 2;
        }
        res += cnt[x - sum];
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);;
    solve();
}