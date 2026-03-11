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
int tc = 1;

int n;
int a[505];
int dp[500005];
int nx[500005];
int sum;
int res;

/*
5
2 3 5 8 13
*/
void solve(){
    cin >> n;
    foru(i, 1, n){
        cin >> a[i];
        sum += a[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    foru(i, 1, n){
        foru(j, 0, sum) nx[j] = dp[j];
        foru(d, 0, sum){
            if(dp[d] != -1){
                if(d + a[i] <= sum) nx[d + a[i]] = max(nx[d + a[i]], dp[d] + a[i]);

                if(d >= a[i])   nx[d - a[i]] = max(nx[d - a[i]], dp[d]);
                else            nx[a[i] - d] = max(nx[a[i] - d], dp[d] - d + a[i]);
            }
        }
        foru(j, 0, sum)  dp[j] = nx[j];
    }
    res = sum - dp[0];
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
