#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int n, q;  cin >> n >> q;
    vector<vector<int>> a(n+3, vector<int>(n+3, 0));

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> a[i][j];
        }
    }

    

    while(q--){
        int quay;   cin >> quay;
        if(quay > 0){
            vector<vector<int>> update(n+3, vector<int>(n+3, 0));
            for(int j=1; j<=n; ++j){
                for(int i=1; i<=n; ++i){
                    update[i][n+1-j] = a[j][i];
                    //cout << i << "," << n+1-j << " = " << j << "," << i << '\n';
                }
            }
            a = update;
        }else{
            vector<vector<int>> update(n+3, vector<int>(n+3, 0));
            for(int j=1; j<=n; ++j){
                for(int i=1; i<=n; ++i){
                    //update[i][n+1-j] = a[j][i];
                    update[j][i] = a[i][n+1-j];
                    //cout << i << "," << n+1-j << " = " << j << "," << i << '\n';
                }
            }
            a = update;
        }
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
