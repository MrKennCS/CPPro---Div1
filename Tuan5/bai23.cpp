#include<iostream>
#include<vector>

using namespace std;

const int lim = 3e4;
int n;
int a[lim + 9];
int pre_a[lim + 9];
vector<vector<int>> b(lim+4, vector<int>(lim+4, 0));


void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre_a[i] = pre_a[i-1] + a[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=i; j<=n; ++j){
            b[i][j] = pre_a[j] - pre_a[i-1];
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}