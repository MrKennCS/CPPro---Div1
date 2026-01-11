#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;    

void solve(){
    foru(i, 1, 9){
        foru(cach, 1, 10 - i)   cout << " ";
        foru(soluong, 1, 2*i-1) cout << i;  cout << '\n';
    }
    foru(i, 0, 9){
        foru(cach, 1, i)    cout << " ";
        foru(soluong, 1, 2*(10 - i) - 1)    cout << i;  cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    #define name "TEST"
    if(fopen(name ".INP", "r")){
        freopen(name ".INP", "r", stdin);
        freopen(name ".OUT", "w", stdout);
    }
    solve();
}