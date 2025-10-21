#include<iostream>

using namespace std;

int n;
int res;

void solve(){
    cin >> n;

    while(n >= 10){
        res++;
        int tmp = n;
        int num = 0;
        while(tmp){
            num = max(num, tmp % 10);
            tmp /= 10;
        }
        n -= num;
    }
    cout << res+1;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}