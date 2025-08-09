#include<iostream>

using namespace std;

const int lim = 250;
int l, w;
int n, k;
int x, y;
int a[lim + 5][lim + 5];
long long pre[lim + 5][lim + 5];
long long res = 1e18;

void solve(){
    cin >> l >> w;
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> x >> y;
        a[x][y] += 1;
    }
    for(int i=1; i<=l; ++i){
        for(int j=1; j<=w; ++j){
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
            //cout << a[i][j] << " ";
        }
        //cout << '\n';
    }
    //cout << "\n\n";
    for(int x1=1; x1<=l; ++x1){
        for(int y1=1; y1<=w; ++y1){
            for(int x2=x1; x2<=l; ++x2){
                for(int y2=y1; y2<=w; ++y2){
                    if(pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1] == k){
                        for(int x3=1; x3<=l; ++x3){
                            for(int y3=1; y3<=w; ++y3){
                                for(int x4=x3; x4<=l; ++x4){
                                    for(int y4=y3; y4<=w; ++y4){
                                        if(pre[x4][y4] - pre[x3-1][y4] - pre[x4][y3-1] + pre[x3-1][y3-1] == k){
                                            if(x3 >= x2 && y3 >= y2 && !(x3 == x2 && y3 == y2)){
                                                /*
                                                cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
                                                cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n\n";
                                                */
                                                if(1LL * 2*(x2 - x1 + 1) + 2*(y2 - y1 + 1) + 2*(x4 - x3 + 1) + 2*(y4 - y3 + 1) < res){
                                                    res = 1LL * 2*(x2 - x1 + 1) + 2*(y2 - y1 + 1) + 2*(x4 - x3 + 1) + 2*(y4 - y3 + 1);
                                                    /*
                                                    cout << "UPDATE: " << 1LL * 2*(x2 - x1 + 1) + 2*(y2 - y1 + 1) + 2*(x4 - x3 + 1) + 2*(y4 - y3 + 1) << '\n';
                                                    cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
                                                    cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n\n";
                                                    */
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res;
}
/*
5 1 6 5
3 1 4 4

5 1 6 5
3 1 4 5

5 1 6 5
3 1 5 4

5 1 6 5
3 1 6 3
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}