#include<iostream>
#include<unordered_map>
using namespace std;

int n;
int a[200009];
long long pre[200009];
long long res;
unordered_map<long long, int> cnt;
/*
8
-1 -4 -3 -8 -5 -3 -8  0

-1 -4 -3
         -8
-1 -4 -3 -8
            -5 -3
         -8 -5 -3
-1 -4 -3 -8 -5 -3
                  -8
            -5 -3 -8
         -8 -5 -3 -8
-1 -4 -3 -8 -5 -3 -8
                      0
                  -8  0
            -5 -3 -8  0
         -8 -5 -3 -8  0
-1 -4 -3 -8 -5 -3 -8  0
      -3 -8 -5
*/
void solve(){
    cin >> n;
    cnt[0] = 1;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i] %= n;
        if(a[i] < 0)    a[i] += n;
        pre[i] = (pre[i-1] + a[i]) % n;
        res += cnt[pre[i]];
        cnt[pre[i]] += 1;
    }

    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}