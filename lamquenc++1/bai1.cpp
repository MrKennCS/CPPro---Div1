#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int a, b;


void solve(){
    cin >> a >> b;
    cout << a + b << '\n' << a - b << '\n' << 1LL * a * b << '\n' << a / b << '\n' << a % b;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}