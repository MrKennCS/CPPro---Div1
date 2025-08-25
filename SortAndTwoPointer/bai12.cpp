#include<iostream>

using namespace std;

int n;
int a[400009];
long long s;
long long pre[400009];
int res = 400010;

void solve(){
    cin >> n >> s;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i=1; i<=2*n; ++i){
        pre[i] = pre[i-1] + a[i];
    }

    int l = 1;
    for(int r=2; r<=2*n; ++r){
        while(pre[r] - pre[l-1] >= s)   l += 1;
        l -= 1;
        cout << r-l+1 << " ";
        res = min(res, r-l+1);
    }


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}