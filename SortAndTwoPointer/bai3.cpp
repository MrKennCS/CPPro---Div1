#include<iostream>

using namespace std;

int n;
int a[100009];
int cnt[100009];

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        cnt[a[i]] += 1;
    }

    int id = 1;
    for(int i=1; i<=100000; ++i){
        for(int j=1; j<=cnt[i]; ++j){
            cout << i << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}