#include<iostream>
#include<bitset>
#include<cstring>
#include<cmath>
#define get_bit(x, y) (((x) >> (y)) & 1)
#define sz(a) (int)a.size()
#define pb push_back

using namespace std;

int n;
string s;
int sum;
int res;

void solve(){
    cin >> s;
    n = sz(s);

    for(int mask=0; mask<(1<<n); ++mask){
        for(int i=0; i<n; ++i){
            sum = 0;
            if(get_bit(mask, i) == 1){
                sum += (s[i] == 'R' ? 1 : -1);
            }
        }
        res += abs(sum);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}