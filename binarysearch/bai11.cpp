#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int n, k;
int a[100009];
vector<long long> pre(100009);
vector<long long> f;

void trau(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    f.push_back(0);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            f.push_back(pre[j] - pre[i-1]);
        }
    }

    sort(f.begin() + 1, f.begin() + n*(n+1)/2 + 1, greater<long long>());

    //for(int i=2; i<=n*(n+1)/2; ++i) cout << f[i] << " ";    cout << '\n';

    for(int i=2; i<=k+1; ++i) cout << f[i] << " ";    
}

int check(ll x){
    int d = 0;
    for(int i=1; i<=n; ++i){
        ll s = 0;
        for(int j=i; j<=n; ++j){
            s += a[j];
            if(s <= x)  d += 1;
        }
    }
    return d;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }

    ll l = -1e15;
    ll r = 1e15;
    ll res = -1;

    while(l <= r){
        ll mid = (r + l) >> 1;
        if(check(mid) >= (n*(n+1)/2) - k + 1){
            res = mid;
            r = mid - 1;
        }else   l = mid + 1;
    }

    cout << res;
}

void toiuu(){

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    
    solve();
}