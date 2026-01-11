#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int a[3];

void solve(){
    foru(i, 0, 2){
        cin >> a[i];
        if(a[i] < 0){
            cout << "NO";
            return ;
        }
    }
    sort(a, a + 3);
    if(a[2]*a[2] == a[0]*a[0] + a[1]*a[1])  cout << "YES";
    else    cout << "NO";
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