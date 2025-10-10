#include<iostream>

using namespace std;

int q;
long long n;

void ans(long long x){
    if(x % 4 == 1)      cout << 1 << '\n';
    else if(x % 4 == 3) cout << 0 << '\n';
    else if(x % 4 == 2) cout << x + 1 << '\n';
    else                cout << x << '\n';
    return ;
}

void solve(){
    /*
    for(int i=1; i<=lim; ++i){
        res ^= i;
        cout << i << " " << res << '\n';
    }
    */
    cin >> n;
    ans(n);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
    
    //solve();

}