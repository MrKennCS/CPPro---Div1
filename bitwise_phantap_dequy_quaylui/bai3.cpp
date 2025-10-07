#include<iostream>
#include<vector>
#include<algorithm>
#define get_bit(x, y) (((x) >> (y)) & 1)
#define sz(a) (int)a.size()
using namespace std;

int n;
int a[20];
int sum;
vector<int> res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=0; i<(1<<n); ++i){
        sum = 0;
        for(int j=0; j<n; ++j){
            if(get_bit(i, j) == 1)  sum += a[j+1];
        }
        res.push_back(sum);
    }

    sort(res.begin(), res.end());

    for(int i=1; i<sz(res); ++i)    cout << res[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}