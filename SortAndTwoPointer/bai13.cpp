#include<iostream>

using namespace std;

int n, m;
int a[10009];
int cnt[10009];
int pre[10009];
int res;

int cnp(int l, int r, int target){
    int m = l + (r + l) / 2;
    while(l <= r){
        m = (r + l) / 2;
        if(a[m] >= target)  r = m - 1;
        else                l = m + 1;
    }
    return m;
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    
    int id = 1;
    for(int i=1; i<=10000; ++i){
        for(int j=1; j<=cnt[i]; ++j){
            a[id] = i;
            id += 1;
        }
    }
    /*
    int i=1;
    int j=n;

    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    cout << '\n';

    while(i <= j){
        if(a[i] + a[j] < m){
            int id_x = cnp(1, n, m - a[i] - a[j]);
            cout << i << " " << j << " " << id_x << " " << a[i] + a[j] + a[id_x] << '\n';
            i += 1;
            j -= 1;
        }else   j -= 1;
    }
    */
   int L, R, x;
   cin >> L >> R >> x;
   cout << cnp(1, n, x);
}

/*
6 20
7 9 6 2 1 5
*/

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}