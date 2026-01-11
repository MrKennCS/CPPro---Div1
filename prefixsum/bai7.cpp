#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

int n, m, q;
int x1, x2, Y1, y2;
ll pre[1003][1003];

void solve(){
    cin >> n >> m;
    foru(i, 1, n){
        foru(j, 1, m){
            cin >> pre[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + pre[i][j];
            //cout << pre[i][j] << " ";
        }
        cout << '\n';
    }
    cin >> q;

    //cout << "---" << pre[2][3] << "---\n";

    while(q--){
        cin >> x1 >> Y1 >> x2 >> y2;
        cout << pre[x2][y2] - pre[x2][Y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][Y1 - 1] << '\n';
        //cout << x1 << " " << Y1 << " " << x2 << " " << y2 << '\n';
        //cout << pre[x2][y2] << " " << pre[x1 - 1][Y1] << " " << pre[x1][Y1 - 1] << " " << pre[x1 - 1][Y1 - 1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}