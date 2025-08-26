#include<iostream>
#include<unordered_map>

using namespace std;

const int LIM = 1e6 + 1e5;
int n;
int a[LIM];
unordered_map<int, int> cnt;

long long calc(int k){
    long long res = 0;
    cnt.clear();
    int l=1;
    int diff = 0;
    for(int r=1; r<=n; ++r){
        if(cnt[a[r]] == 0)    diff += 1;
        cnt[a[r]] += 1;
        while(l + 1 <= r && diff - (cnt[a[l]] == 1) > k)  l += 1;
        if(diff <= k)   res += r - l + 1;
    }
    return res;
}

void solve(){
    int l, u;
    cin >> n >> l >> u;
    for(int i=1; i<=n; ++i) cin >> a[i];

    cout << calc(u) - calc(l-1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}