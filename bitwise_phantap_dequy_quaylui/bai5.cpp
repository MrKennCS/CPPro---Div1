#include<iostream>
#define ll long long
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

int n, q;
int a[100009];
ll res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    res = 0;
    for(int bit=0; bit<32; ++bit){
        int cnt_0 = 0;
        int cnt_1 = 0;
        for(int i=1; i<=n; ++i){
            if(get_bit(a[i], bit) == 1) cnt_1++;
            else                        cnt_0++;
        }
        res += 1LL * cnt_0 * cnt_1 * (1LL << bit);
    }
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}