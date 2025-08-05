#include<iostream>

using namespace std;

int n;
int a[100009];
long long pre[100009];
int cnt[100009];
long long res;

void solve(){
    cin >> n;
    cnt[0] = 1;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        cnt[pre[i]] += 1;
    }


    for(int i=1; i<=n; ++i){
        //cout << (cnt[pre[i]] * (cnt[pre[i]] - 1)) / 2 << '\n';
        res += (cnt[pre[i]] * (cnt[pre[i]] - 1)) / 2;
        cnt[pre[i]] = 0;
    }

    cout << res;

    /*
    for(int i=1; i<=n; ++i){
        cnt[pre[i]] += 1;
        res += (cnt[pre[i]]*(cnt[pre[i]] - 1) / 2);
    }
    */
}
/*
8
1 -1  3 -2 -1  4 -3 -1
1  0  3  1  0  4  1  0

1 -1
  -1  3 -2
      3 -2 -1
1 -1  3 -2 -1
               4 -3 -1
      3 -2 -1  4 -3 -1
           -1  4 -3
1 -1  3 -2 -1  4 -3 -1
  -1  3 -2 -1  4 -3
-> 6
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}