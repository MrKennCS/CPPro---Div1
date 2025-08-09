#include<iostream>

using namespace std;

const int lim = 1e5;
int q;
int l, r;
int a[lim + 9];
int pre[lim + 9];



int demuoc(int x){
    int ans = 0;
    for(int i=1; i*i<=x; ++i){
        if(x % i == 0)  ans += (x/i == i ? 1 : 2);
    }
    return ans;
}

void solve(){
    cin >> q;

    for(int i=1; i<=lim; ++i){
        pre[i] = pre[i-1] + (demuoc(i) == 4);
    }

    while(q--){
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}