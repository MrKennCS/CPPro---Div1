#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

int n, k;
int pre[1003][1003];
int res;

void solve(){
    cin >> n >> k;
    foru(i, 1, n){
        foru(j, 1, n){
            cin >> pre[i][j];
            pre[i][j] += (pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
        }
    }
    foru(i, k, n){
        foru(j, k, n){
            res = max(res, pre[i][j] - pre[i][j - k] - pre[i - k][j] + pre[i - k][j - k]);
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}