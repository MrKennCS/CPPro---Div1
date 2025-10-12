#include<iostream>
#include<vector>

using namespace std;

int n;
int sum_a, sum_b;
int a[25];
int pos;
int ans[25];
int ok;

void backtrack(int pos){
    for(int i=1; i<=2; ++i){
        ans[pos] = i;
        if(i == 1)  sum_a += a[pos];
        else        sum_b += a[pos];

        if(pos == n){
            if(sum_a == sum_b){
                for(int j=1; j<=n; ++j){
                    cout << ans[j];
                }
                cout << '\n';
                ok++;
            }
        }else   backtrack(pos+1);

        if(i == 1)  sum_a -= a[pos];
        else        sum_b -= a[pos];
    }
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    backtrack(1);

    if(ok == 0){
        cout << -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}