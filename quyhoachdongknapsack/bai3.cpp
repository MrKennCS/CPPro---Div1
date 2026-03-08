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
const int limN = 1e2 + 3;
const int limV = 1e5 + 5;
int tc = 1;

int n, W;
int w[limN];
int v[limN];
ll dp[limV];
int sum;

void solve(){
    cin >> n >> W;

    foru(i, 1, n){
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;

    foru(i, 1, n){
        ford(j, sum, v[i]){
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    ford(i, sum, 0) if(dp[i] <= W){
        cout << i;
        return ;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
