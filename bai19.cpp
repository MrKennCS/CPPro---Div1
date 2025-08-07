#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
int l, r;
int a[200009];
int pre[200009];
long long res;

bool cmp(int a, int b){
    return (a >= b);
}

void solve(){
    cin >> n >> q;

    for(int i=1; i<=n; ++i) cin >> a[i];

    while(q--){
        cin >> l >> r;
        pre[l]   += 1;
        pre[r+1] -= 1;
    }

    for(int i=1; i<=n; ++i) pre[i] += pre[i-1];
    
    sort(pre + 1, pre + n + 1, cmp);
    sort(a + 1, a + n + 1, cmp);
    for(int i=1; i<=n; ++i){
        if(pre[i] == 0) break;
        res += 1LL * pre[i] * a[i];
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}