#include<iostream>
#include<stack>
#include<bitset>
#include<vector>
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)
using namespace std;

vector<int> res;
int n;

void sinh(){
    for(int i=0; i<=1; ++i){
        res.push_back(i);

        if(sz(res) == n){
            for(int j=0; j<sz(res); ++j)    cout << res[j];
            cout << '\n';
        }else sinh();

        res.pop_back();
    }
}

void solve(){
    cin >> n;
    sinh();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}