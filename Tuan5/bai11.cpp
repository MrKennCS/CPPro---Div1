#include<iostream>

using namespace std;

int n, q;
int x1, y1, x2, y2;
int a[505][505];
int trang[505][505];
int den[505][505];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> a[i][j];
            trang[i][j] = (trang[i-1][j] + trang[i][j-1] - trang[i-1][j-1] + ((i + j) & 1 ? 0 : a[i][j]));
            den[i][j]   = (den[i-1][j]   + den[i][j-1]   - den[i-1][j-1]   + ((i + j) & 1 ? a[i][j] : 0));
        }
    }
    /*
    Check trang[i][j] va den[i][j]

    cout << '\n';
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << trang[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout << den[i][j] << " ";
        }
        cout << '\n';
    }
    */
    cin >> q;
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        int white = trang[x2][y2] - trang[x1-1][y2] - trang[x2][y1-1] + trang[x1-1][y1-1];
        int black = den[x2][y2]   - den[x1-1][y2]   - den[x2][y1-1]   + den[x1-1][y1-1];
        cout << abs(white - black) << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}