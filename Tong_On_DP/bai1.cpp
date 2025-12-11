#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
int a[100005];
int l, r;
int pre[100005];

void solve(){
    cin >> n >> q;
    
    for(int i=1; i<=n; ++i) cin >> a[i];
    
    while(q--){
        cin >> l >> r;
        pre[l]++;
        pre[r+1]--;
    }

    for(int i=1; i<=n; ++i) pre[i] += pre[i-1];

    sort(pre + 1, pre + n + 1);
    sort(a + 1, a + n + 1);

    long long res = 0;
    for(int i=1; i<=n; ++i){
        res += 1LL * a[i] * pre[i];
    }

    cout << res;
}

void review(){
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];

    while(q--){
        cin >> l >> r;
        pre[l]++;
        pre[r+1]--;
    }

    for(int i=1; i<=n; ++i) pre[i] += pre[i-1];

    sort(pre + 1, pre + n + 1);
    sort(a + 1, a + n + 1);

    long long res = 0;
    for(int i=1; i<=n; ++i) res += 1LL * a[i] * pre[i];

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    review();
}