#include<iostream>
#define int long long
using namespace std;

int n;

int demuoc(int a){
    int cnt = 0;
    for(int i=1; 1LL*i*i<=a; ++i){
        if(a % i == 0)  cnt += (a/i == i ? 1 : 2);
    }
    return cnt;
}

void solve(){
    int tm = 1;
    cin >> n;
    int N = n;
    if(n == 1){
        cout << 1 << '\n' << 1;
        return ;
    }
    for(int i=2; 1LL*i*i<=n; ++i){
        while(n % i == 0){
            if(tm == 1){
                cout << i;
                tm += 1;
            }
            else        cout << "*" << i;
            n /= i;
        }
    }
    if(n != 1){
        if(tm == 1) cout << n;
        else        cout << "*" << n;
    }
    cout << '\n';

    cout << demuoc(N);
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}