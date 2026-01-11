#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int a, b, c, d;

void solve(){
    cin >> a >> b >> c >> d;
    if(max(a, c) <= min(b, d))  cout << "YES";
    else            cout << "NO";
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