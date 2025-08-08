#include<iostream>
#include<unordered_map>

using namespace std;

int n;
int a[200009];
long long res;
long long pre[200009];
unordered_map<int, int> cnt;

void solve(){
    /*
    8
    -1 2 3 -4 2 3 -3 -1
    */
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int r=1; r<=n; ++r){
        cnt[pre[r-1]] += 1;
        if(pre[r] % n == 0) res += cnt[pre[r]];
    }

    cout << res;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}