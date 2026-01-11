#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

const int limN = 1e5 + 3;
unomap<ll, int> cnt;
ll pre[limN];
int a[limN];
int n;
ll res;

void solve(){
    cin >> n;
    foru(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    //foru(i, 1, n)   cout << pre[i] << " ";  cout << '\n';
    foru(i, 1, n){
        cnt[pre[i - 1]]++;
        res += cnt[pre[i]];
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}