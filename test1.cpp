#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int n, m;   cin >> n >> m;

    vector<vector<int>> a(n + 4, vector<int>(m + 4, 0));

    /*
    1 2 3   (1, 1)  (1, 2)  (1, 3)
    4 5 6   (2, 1)  (2, 2)  (2, 3)
    7 8 9   (3, 1)  (3, 2)  (3, 3)
    */

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> update(n+3, vector<int>(n+3, 0));
    for(int j=1; j<=n; ++j){
        for(int i=1; i<=m; ++i){
            update[i][n+1-j] = a[j][i];
                    //cout << i << "," << n+1-j << " = " << j << "," << i << '\n';
        }
    }
    a = update;
    swap(n, m);
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}