#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)

using namespace std; 

int cnt;
int n;
int a[200003];
ll pre[200003];

ll get(int L, int R){
    if(L > R)   return 0;
    return pre[R] - pre[L - 1];
}

void solve(){
    cin >> n;
    foru(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    foru(i, 1, n - 1){
        cnt += (get(1, i) == get(i + 1, n));
    }

    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}