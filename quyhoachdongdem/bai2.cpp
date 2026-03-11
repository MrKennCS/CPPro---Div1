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

const int mod = 14062008;
int tc = 1;

/*
Goi dp 
*/

int n, k;
bool hu[100005];
int dp[100005];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n >> k;

    //memset(hu, 0, sizeof(hu)); //

    foru(i, 1, k){
        int tmp;    cin >> tmp;
        hu[tmp] = true;
    }
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;

    foru(i, 1, n - 1){
        if(hu[i])   continue;
        add(dp[i + 1], dp[i]);
        add(dp[i + 2], dp[i]);
    }
    /*

    */

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
