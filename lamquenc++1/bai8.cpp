#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;    

int n, q;
int a[205];
int pos, val;

void solve(){
    cin >> n >> q;
    foru(i, 1, n)   cin >> a[i];
    while(q--){
        cin >> pos >> val;
        ford(i, n + 1, pos + 1) a[i] = a[i - 1];
        a[pos] = val,   n++;
        foru(i, 1, n)   cout << a[i] << " ";   cout << '\n'; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    
    solve();
}