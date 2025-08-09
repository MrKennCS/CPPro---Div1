#include<iostream>

using namespace std;

int n, m, q, T;
int a[505][505];
int r, d, sum_r, sum_d;
int x1, y1, x2, y2;
int pre[1010][1010];

void truyvan_0(){
    cin >> r >> d;
    sum_r += r;
    sum_d += d;
    //cout << "Truy van 0: " << sum_r << " " << sum_d << '\n';
}

void truyvan_1(){
    cin >> x1 >> y1 >> x2 >> y2;

    sum_r %= m;
    sum_d %= n;

    //cout << sum_r << " " << sum_d << '\n';

    x1 += sum_d;
    y1 += sum_r;
    x2 += sum_d;
    y2 += sum_r;

    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
    
    cout << pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1] << '\n';
}
/*
1 2 3
4 5 6

6 4 5
3 1 2

1 2 2 3 -> 2 4 3 5
*/
void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
            pre[i][j]     = a[i][j];
            pre[i+n][j]   = a[i][j];
            pre[i][j+m]   = a[i][j];
            pre[i+n][j+m] = a[i][j];
        }
    }
    /*
    for(int i=1; i<=2*n; ++i){
        for(int j=1; j<=2*m; ++j){
            cout << pre[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n\n";
    */

    for(int i=1; i<=2*n; ++i){
        for(int j=1; j<=2*m; ++j){
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            //cout << pre[i][j] << " ";
        }
        //cout << '\n';
    }
    //cout << "\n\n";

    cin >> T;
    while(T--){
        cin >> q;
        if(q == 0)  truyvan_0();
        else        truyvan_1();
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
    /*
    TEST1:
    2 3
    1 2 3
    4 5 6
    2
    0 2 1
    1 1 2 2 3

    TEST2:
    4 5
    1 2 5 2 1
    4 3 1 2 3
    2 3 5 3 1
    3 2 1 1 5
    5
    0 2 1
    1 2 2 3 4
    0 2 4
    1 1 1 1 1
    1 3 2 4 5
    */
}