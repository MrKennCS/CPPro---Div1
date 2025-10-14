#include<iostream>
#include<vector>
#define sz(a) (int)a.size()
#define pb push_back
using namespace std;

int n;
int cnt[20];
vector<int> res;

void backtrack(){
    for(int i=1; i<=n; ++i){
        if(cnt[i] == 0) res.pb(i);
        else            continue;
        cnt[i] = 1;

        if(sz(res) == n){
            for(int j=0; j<n; ++j){
                cout << res[j] << " ";
            }
            cout << '\n';
        }else   backtrack();

        res.pop_back();
        cnt[i] = 0;
    }
}

void solve(){
    cin >> n;

    backtrack();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}