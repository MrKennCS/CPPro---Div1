#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int a[1000009];
int cnt[1000009];
long long res;

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    
    int id = 1;
    for(int i=1; i<=1000000; ++i){
        for(int j=0; j<cnt[i]; ++j){
            a[id] = i;
            id += 1;
        }
    }

    int r = n;
    for(int l=1; l<=r; ++l){
        while(l < r && a[l] + a[r] > m)    r -= 1;
        if(r - l == 0 && r - l == 1)    continue;
        else                            res += (r - l);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}