#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

int res = 500 * 500 + 5;
int n;
int pre[505][505];
int cmp[6];

int chenhlech(int x, int y){
    cmp[0] = pre[x][y];
    cmp[1] = pre[x][n] - pre[x][y];
    cmp[2] = pre[n][y] - pre[x][y];
    cmp[3] = pre[n][n] - pre[n][y] - pre[x][n] + pre[x][y];

    //foru(i, 0, 3)   cout << cmp[i] << " ";  cout << '\n';
    sort(cmp, cmp + 4);
    //foru(i, 0, 3)   cout << cmp[i] << " ";  cout << '\n';
    return (cmp[3] - cmp[0]);
}

void solve(){
    cin >> n;
    foru(i, 1, n){
        foru(j, 1, n){
            cin >> pre[i][j];
            pre[i][j] += (pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
            //cout << pre[i][j] << " ";
        }
        //cout << '\n';
    }

    foru(i, 1, n - 1){
        foru(j, 1, n - 1){
            res = min(res, chenhlech(i, j));
            //cout << chenhlech(i, j) << " ";
        }
    }

    cout << res << '\n';

    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}