#include<iostream>
#include<stacK>

using namespace std;

int n, m;
int a[1005][1005];
int hi[1005];
int res;
int l[1005], r[1005];
stack<int> st;

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(hi[j] == 0)  hi[j] = 0;
            else            hi[j] += 1;
        }

        for(int j=1; j<=m; ++j){
            
        }
    }
}
/*
11 13
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 1 1 1 1 1 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 1 1
0 0 0 0 0 1 0 0 0 0 0 1 1

0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 2 1 0 0 0 0 0 0
0 0 1 1 2 3 2 1 1 0 0 0 0
0 0 2 2 3 4 3 2 2 0 0 0 0
0 1 3 3 4 5 4 3 3 1 0 0 0
1 2 4 4 5 6 5 4 4 2 1 0 0
0 3 5 5 6 7 6 5 5 3 0 0 0
0 0 6 6 7 8 7 6 6 0 0 0 0
0 0 7 7 8 9 8 7 7 0 0 0 0
0 0 0 0 9 109 0 0 0 0 12 12
0 0 0 0 0 11 0 0 0 0 0 12 12 
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}