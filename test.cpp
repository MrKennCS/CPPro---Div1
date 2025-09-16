#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int a[100][100];
vector<int> vec;
stack<int> st;
set<int> arr;
priority_queue<int, vector<int>, greater<vector<int>>> qu;

void solve(){
    int n, m;    cin >> n >> m;
    vector<vector<int>> a(n+3, vector<int>(m+3, 0));

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
        }
        vector<int> tmp = a[i];
        sort(tmp.begin()+1, tmp.begin()+m+1);

        a[i] = tmp;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    /*
    freopen("BA.INP", "r", stdin);
    freopen("BA.OUT", "w", stdout);
    */
    solve();
}
