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

int n, m;
int s;
vector<ii> vec;
vector<ii> tmp;
vector<pair<ii, int>> cnt;
int dp[100005];

/*
9 15
6 5
5 6
6 4
6 6
6 6
6 6
3 5
7 2
7 2
*/

void solve(){
    cin >> n >> m;

    foru(i, 1, n){
        int w, v;
        cin >> w >> v;
        tmp.pb({w, v});
    }

    sort(tmp.begin(), tmp.end());
    cout << '\n';

    tmp.pb({0, 0});
    int dem = 1;
    
    foru(i, 1, n){
        if(tmp[i - 1].fi != tmp[i].fi || tmp[i - 1].se != tmp[i].se){
            cnt.pb({{tmp[i - 1].fi, tmp[i - 1].se}, dem});
            dem = 1;
            s++;
        }else       dem++;
    }

    foru(i, 0, s - 1){
        int w = cnt[i].fi.fi;
        int v = cnt[i].fi.se;
        int a = cnt[i].se;

        int k = 1;

        while(a > k){
            vec.pb({k * w, k * v});
            a -= k;
            k *= 2;
        }
        if(a > 0)   vec.pb({a * w, a * v});
    }

    memset(dp, -0x3f, sizeof(dp));
    dp[0] = 0;

    for(ii item : vec){
        ford(j, m, item.fi){
            dp[j] = max(dp[j], dp[j - item.fi] + item.se);
        }
    }

    int res = 0;
    foru(i, 0, m)   res = max(res, dp[i]);

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
