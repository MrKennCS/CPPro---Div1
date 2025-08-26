#include<iostream>

using namespace std;

int n;
unsigned long long s;
int a[400009];
unsigned long long pre[400009];
int res = 2000000;

void solve(){
    cin >> n >> s;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i=1; i<=2*n; ++i)   pre[i] = pre[i-1] + a[i];
    
    int l=1;
    for(int r=1; r<=2*n; ++r){
        while(pre[r] - pre[l-1] >= s)   l += 1;
        int cur_l = (l == 1 ? 1 : l-1);
        if(pre[r] - pre[cur_l-1] >= s)  res = min(res, r-cur_l+1);
        //cout << cur_l << " " << r << " " << pre[r] - pre[cur_l-1] << '\n';
    }
    cout << (res <= n ? res : -1);

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}