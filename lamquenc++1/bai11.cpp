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
const int offset = 2000;
int tc = 1;

/*

*/

int n, K;
int x[2003];
int ar[2003];
int cnt[2005 + offset]; 
int res;

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

void trau(){
    cin >> n >> K;
    for(int i=1; i<=n; ++i) cin >> x[i];

    for(int a=1; a<=n; ++a){
        for(int b=a+1; b<=n; ++b){
            for(int c=b+1; c<=n; ++c){
                for(int d=c+1; d<=n; ++d){
                    if(x[a] + x[b] + x[c] + x[d] == K)  res++;
                }
            }
        }
    }
    cout << res;
}

void solve(){
    cin >> n >> K;
    for(int i=1; i<=n; ++i) cin >> ar[i];
    //      a[i] + a[j] + a[k] + a[l] == K
    // =>   a[i] + a[j] == K - a[k] - a[l]

    for(int j=n-2; j>=2; --j){
        int k = j + 1;
        for(int l = k + 1; l<=n; ++l){
            cnt[ar[k] + ar[l] + offset]++;
        }

        for(int i=1; i<=j-1; ++i){
            if(K - ar[i] - ar[j] + offset >= 0  && K - ar[i] - ar[j] + offset <= 4000)  res += cnt[K - ar[i] - ar[j] + offset];
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--){
        solve();
        //trau();
    }
}
