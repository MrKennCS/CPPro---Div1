#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std; 

const int limN = 2e5 + 3;
int n;
int a[limN];
ll sum;
ll res;
int mx = -1e9 - 9;

/*
ll get(int L, int R){
    if(L > R)   return 0;
    return pre[R] - pre[L - 1];
}
*/

void solve(){
    cin >> n;

    foru(i, 1, n){
        cin >> a[i];
        sum += a[i];
        if(sum < 0) sum = 0;
        if(a[i] < 0)    mx = max(mx, a[i]);
        res = max(res, sum);
    }

    cout << (res == 0 ? mx : res);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}