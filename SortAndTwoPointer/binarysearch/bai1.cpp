#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int a[100009];



void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    int *lower = lower_bound(a + 1, a + n + 1, k);
    int *upper = upper_bound(a + 1, a + n + 1, k);

    cout << upper - lower << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}