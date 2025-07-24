#include<iostream>

using namespace std;

int n;
int cnt;

void solve(){
    cin >> n;
    for(int i=1; i*i<=n; ++i){
        if(n % i == 0){
            cnt += (n / i == i ? 1 : 2);
        }
    }

    cout << cnt;
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}