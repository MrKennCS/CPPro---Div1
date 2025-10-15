#include<iostream>
#include<vector>
#define sz(a) (int)a.size()
#define pb push_back

using namespace std;

int n;
const int mod = 1e9 + 7;
int res;

/*
f[i] =

f[1] = 1
f[2] = 2
f[3] = 4
f[4] = 8
f[5] =

1 1 1 1
1 1 2
1 2 1
2 1 1
2 2
1 3
3 1
4

*/
vector<int> state;
int sum;

void backtrack(int target){
    for(int i=1; i<=6; ++i){
        sum += i;
        state.pb(i);

        if(sum >= target){
            if(sum == target){
                res++;
            }
        }else   backtrack(target);

        sum -= i;
        state.pop_back();
    }
}

void solve(){
    cin >> n;

    backtrack(10);
    cout << '\n' << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
