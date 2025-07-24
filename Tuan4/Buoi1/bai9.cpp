#include<iostream>

using namespace std;

int demuoc(int x){
    int res = 0;
    for(int i=1; i*i<=x; ++i){
        if(x % i == 0)  res += (x/i == i ? 1 : 2);
    }
    return res;
}

int n;

void solve(){
    cin >> n;
    int res = 0;
    for(int i=1; i*i<=n; ++i){
        if(n % i == 0){
            res += (demuoc(i) == 4);
            if(n/i != i){
                res += (demuoc(n/i) == 4);
            }
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}