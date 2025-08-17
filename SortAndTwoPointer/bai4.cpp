#include<iostream>
#include<algorithm>

using namespace std;

int n, q;
int a[110009];
int cnt[110009];
int x, num;

void truyvan1(){
    n += 1;
    a[n] = num;
    cnt[num] += 1;
}

void truyvan2(){
    int id = 1;
    for(int i=1; i<=1000; ++i){
        for(int j=1; j<=cnt[i]; ++j){
            a[id] = i;
            id += 1;
        }
    }

    cout << a[num] << '\n';
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    cin >> q;
    while(q--){
        cin >> x >> num;
        if(x == 1)  truyvan1();
        else        truyvan2();
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}