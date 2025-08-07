#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, a, b;
int res;
int val[1005][1005];

void solve(){
    cin >> n >> m >> a >> b;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> val[i][j];
        }
    }
    for(int i=a; i<=n; ++i){
        for(int j=b; j<=m; ++j){
            vector<int> tmp;
            for(int x=i-a+1; x<=i; ++x){
                for(int y=j-b+1; y<=j; ++y){
                    tmp.push_back(val[x][y]);
                }
            }
            sort(tmp.begin(), tmp.end());
            res = max(res, tmp[(a*b-1)/2]);
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}