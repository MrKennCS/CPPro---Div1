#include<iostream>
#include<vector>
#define sz(a) (int)a.size()

using namespace std;

int c, n;
int a[20];
vector<int> state;
int sum;
int res;

void sinh(){
    int st = (state.empty() ? 0 : state.back());

    for(int i=st+1; i<=n; ++i){
        state.push_back(i);
        sum += a[i];

        if(sum <= c){
            //for(int i=0; i<sz(state); ++i)  cout << state[i] << " ";    cout << '\n';
            //cout << "SUM " << sum << '\n';
            res = max(res, sum);
            sinh();
        }
        

        state.pop_back();
        sum -= a[i];
    }
}

void solve(){
    cin >> c >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }

    sinh();

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}