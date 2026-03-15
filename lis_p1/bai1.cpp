/*
WARNING: ĐÂY LÀ CODE 100% DO AI TẠO RA
MỤC ĐÍCH SUBMIT CODE LÀ ĐỂ DEBUG VÀ RÚT KINH NGHIỆM, KHÔNG MANG MỤC ĐÍCH SUBMIT LẤY ĐIỂM QUA BÀI
*/

#include <iostream>
#include <vector>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define umap unordered_map
#define uset unordered_set

#define sz(a) (int)a.size()
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

/*

*/

int n;
int a[25005];
int dp[25005][2];

void solve(){
    cin >> n;
    for(int i=1; i<n; ++i)  cin >> a[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;

    for(int i=1; i<=n; ++i){
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i]);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a[i]);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
    }

    cout << dp[n][1];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}