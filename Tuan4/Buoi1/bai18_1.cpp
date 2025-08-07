#include<iostream>
#include<algorithm>

using namespace std;


void solve(){
    int n, m;   cin >> n >> m;
    int tmp = __gcd(n, m);
    
    for(int i=1; i<=tmp; ++i){
        if(tmp % i == 0)    cout << i << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}