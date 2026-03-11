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
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define foruc(i, a, b, c) for(int i=a; i<=b; i+=c)
#define fordc(i, a, b, c) for(int i=a; i>=b; i-=c)

#define fi first
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define lb lower_bound
#define up upper_bound

const int mod = 1e9 + 7;
int tc = 1;

int n, k;
int a[1000005];
ll sum[1000005];
ll mx_left[1000005];
ll mx_right[1000005];
ll cur;
ll res = 1e18;

void solve(){
    cin >> n >> k;
    foru(i, 1, n)   cin >> a[i];

    foru(i, 1, k)   cur += a[i];
    sum[1] = cur;

    foru(i, 2, n - k + 1){
        cur = cur - a[i - 1] + a[i + k - 1];
        sum[i] = cur;
    }

    foru(i, 1, n - k + 1)   mx_left[i] = max(mx_left[i - 1], sum[i]);
    ford(i, n - k + 1, 1)   mx_right[i] = max(mx_right[i + 1], sum[i]);

    foru(i, 1, n - k + 1){
        ll ri = 0;
        ll le = 0;

        if(i - k >= 1)          le = mx_left[i - k];
        if(i + k <= n - k + 1)  ri = mx_right[i + k];

        ll tmp = max(ri, le);
        res = min(res, tmp);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);    cin.tie(0);

    while(tc--) solve();
}