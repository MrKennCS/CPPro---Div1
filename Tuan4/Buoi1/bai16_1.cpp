#include<bits/stdc++.h>

using namespace std;

int n;
long long x;
long long a[100009];
long long pre[100009];

void solve(){
    cin >> n >> x;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        /*
            a[i] = 2
            x = 5;

            x/a[i]+1 = 3
        */
        pre[i] = (x / a[i] + 1) * a[i];
        if(pre[i] - a[i] == x)  pre[i] = x;
        // so dau tien chia het cho a[i] ma >= x
        //cout << pre[i];
    }

    sort(pre + 1, pre + n + 1);

    cout << pre[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    solve();
}