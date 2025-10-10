#include<iostream>
#include<vector>
#include<algorithm>

#define sz(a) (int)a.size()
using namespace std;

int n;
vector<int> state;
int sum;

void gen(){
    int start = (state.empty() ? 1 : state.back());
    for(int i=start; i<=n; ++i){
        sum += i;
        state.push_back(i);

        if(sum >= n){
            if(sum == n){
                /*
                */
               cout << n << " = ";
               cout << state[0];
               for(int j=1; j<sz(state); ++j){
                   cout << "+" << state[j];
               }
               cout << '\n';
            }
        }else   gen();

        sum -= i;
        state.pop_back();
    }
}

void solve(){
    cin >> n;

    gen();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}