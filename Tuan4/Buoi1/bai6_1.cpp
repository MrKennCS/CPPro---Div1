#include<bits/stdc++.h>

using namespace std;

void factor(int n){
    int tm = 0;
    for(int i=2; i*i<=n; ++i){
        while(n % i == 0){
            if(tm == 0){    cout << i;  tm += 1;    }
            else{           cout << "*" << i;       }
            n /= i;
        }
    }
    if(n > 1){
        if(tm == 0) cout << n;
        else        cout << "*" << n;
    }
}

void demuoc(int n){
    int res = 0;
    for(int i=1; i*i<=n; ++i){
        if(n % i == 0)  res += (n/i == i ? 1 : 2);
    }
    cout << '\n' << res;
}

void solve(){
    int n;  cin >> n;
    factor(n);
    demuoc(n);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}