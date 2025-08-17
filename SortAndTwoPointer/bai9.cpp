#include<iostream>
#include<unordered_map>

using namespace std;

int n, k;
int   a[1000006];
unordered_map<int, int> cnt;
long long res;

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(a[i] > k)   break;
        res += (cnt[k - a[i]]);
        cnt[a[i]] += 1;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}