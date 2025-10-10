#include<iostream>
#include<vector>
#include<bitset>

#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)
#define ll long long

using namespace std;

int n;
int h[20];
int w[20][20];
ll sum;
ll res;

void solve(){
    cin >> n;
    for(int i=0; i<n; ++i)      cin >> h[i];
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-i-1; ++j){
            cin >> w[i][j];
        }
    }

    for(int mask=0; mask<(1LL << n); ++mask){
        for(int i=0; i<n; ++i){
            if(get_bit(mask, i) == 0)   sum += (-1)*(h[i]);
            else                        sum += h[i];
        }

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                sum += w[i][j] * (get_bit(mask, i) == 1 ? 1 : (-1)) * (get_bit(mask, j) == 1 ? 1 : (-1));
            }
        }

        res = min(res, sum);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}