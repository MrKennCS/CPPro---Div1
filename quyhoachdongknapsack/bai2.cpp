// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

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
const int LIMN = 1e3 + 3;
const int LIMW = 1e7 + 5;
int tc = 1;

int n, W;
int w[LIMN];
int v[LIMN];
ll dp[LIMW];

void solve(){
    cin >> n >> W;
    foru(i ,1, n){
        cin >> w[i] >> v[i];
    }

    dp[0] = 0;
    foru(i, 1, n){
        ford(j, W, w[i]){
            if(dp[j - w[i]] + v[i] > dp[j]) dp[j] = dp[j - w[i]] + v[i];
            //dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
        }
    }

    /*
    foru(i, 1, n){
        foru(j, 1, W){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    */

    cout << dp[W];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
