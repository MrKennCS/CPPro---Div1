#include<iostream>

using namespace std;

int n, q;
int a[100009];

int mx = -1000000001;
int sum;
int res1;
int res2;

void solve(){
    cin >> n;

    sum = 0;
    res1 = 0;
    res2 = 0;
    mx = -1000000001;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        sum += a[i];
        if(a[i] > 0)    res1 += a[i];
        if(a[i] < 0)    mx = max(mx, a[i]);
        if(sum < 0)     sum = 0;
        res2 = max(res2, sum);
    }

    cout << (res1 == 0 ? mx : res1) << " " << (res2 == 0 ? mx : res2) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}