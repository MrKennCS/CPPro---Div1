#include<iostream>
#define ll long long
#define ull unsigned long long
using namespace std;

int n;
ull a[200009];
ull num;

void trau(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=63; i>=0; --i){
        num = (1LL << i);
        //cout << "GEY\n";
        //cout << num << '\n';
        for(int j=1; j<=n; ++j){
            if(a[j] % num == 0){
                cout << num;
                return ;
            }
        }
    }
    /*
    4
    1 3 7 9

    */
}

void solve(){
    ll res = 0;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        int last = __builtin_ctzll(a[i]);
        res = max(res, (1LL << last));
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //trau();
    solve();
}