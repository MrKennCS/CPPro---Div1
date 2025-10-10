#include<iostream>
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

int n, q;
int a[100009];
long long res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];


    for(int i=0; i<32; ++i){
        int cnt_0, cnt_1;
        cnt_0 = cnt_1 = 0;
        for(int j=1; j<=n; ++j){
            if(get_bit(a[j], i) == 1)   cnt_1++;
            else                        cnt_0++;
        }

        cnt_1 *= cnt_0;

        res += cnt_1 * (1LL << i);
    }

    cout << res << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}