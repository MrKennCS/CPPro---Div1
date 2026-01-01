#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <functional>
#include <numeric>

#define double long double
#define ii pair<int,int>
#define iii pair<int, ii >
#define fi first
#define se second
#define getbit(x,y) (((x)>>(y))&1ll)
#define turnon(x,y) ((x)|(1ll<<y))
#define turnof(x,y) ((x)^(1ll<<y))
#define oo 1e18
#define pb push_back
#define all(x) x.begin(),x.end()
#define con(mask) mask=(mask-1)&mask
#define Unique(val) val.erase(unique(val.begin(),val.end()),val.end())
#define ll long long
#define rand_int mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand_ll mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const double pi = acos(-1);
const double esp = 1e-6;
int base = 100000;

using namespace std;

int n;
int c[105];
int dp[100005];

void solve() {

    cin >> n;

    int tong = 0;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];

        tong += c[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int sum = tong; sum >= c[i]; sum--) {
            dp[sum] = max(dp[sum], dp[sum - c[i]]);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= tong; i++) {
        if(dp[i]) {
            cnt++;
        }
    }

    cout << cnt << "\n";

    for(int i = 1; i <= tong; i++) {
        if(dp[i]) {
            cout << i << " ";
        }
    }


}

signed main() {


    #ifndef ONLINE_JUDGE
    freopen("inp.inp", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif


    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
    }
}
//      ProTeam
//(¯`·.·´¯) (¯`·.·´¯)
//`·.¸(¯`·.·´¯)¸ .·
//×°× ` ·.¸.·´ ×°×
