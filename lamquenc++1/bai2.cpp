#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int n;

void solve(){
    cin >> n;
    if((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))  cout << "Nam nhuan";
    else                                                cout << "Khong la nam nhuan";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    #define name "DAONGUOC"
    if(fopen(name ".INP", "r")){
        freopen(name ".INP", "r", stdin);
        freopen(name ".OUT", "w", stdout);
    }
    solve();
}