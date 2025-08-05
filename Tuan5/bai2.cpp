#include<iostream>

using namespace std;

int n;
int a[200009];
long long sum;
long long res;
int mx = -1000000001;

void solve(){
    cin >> n;
    
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i){
        sum += 1LL * a[i];
        if(a[i] < 0)    mx = max(mx, a[i]);
        if(sum < 0)     sum = 0;
        res = max(res, sum);
    }
    cout << (res == 0 ? mx : res);

}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}