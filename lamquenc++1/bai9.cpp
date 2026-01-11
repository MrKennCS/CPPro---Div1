#include<bits/stdc++.h>
#define ll long long
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

int n;
int a[100005];

void solve(){
    cin >> n;
    foru(i, 1, n)   cin >> a[i];
    sort(a, a + n + 1);
    cout << a[n] << " " << a[n - 1] << " " << a[n - 2];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}