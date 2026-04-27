#include<bits/stdc++.h>
#define ll long long
#define FORU(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a; i>=b; --i)

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


ll randInt(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    freopen("CURRENT.INP", "w", stdout);

//    int n = randInt(1, 20);
//    int W = randInt(1, 50);
//    cout << n << " " << W << '\n';
//    FORU(i, 1, n){
//        int w = randInt(3, 5);
//        int v = randInt(10, 50);
//        cout << w << " " << v << '\n';
//    }


    int n = randInt(1, 20);
    int W = randInt(100000000, 1000000000);
    cout << n << " " << W << '\n';
    FORU(i, 1, n){
        int w = randInt(1000000, 10000000);
        int v = randInt(100, 1000);
        cout << w << " " << v << '\n';
    }
}
/*

#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a; i>=b; --i)
#define getbit(x, y) (((x) >> (y)) & 1)
#define sz(a) (int)a.size()
#define ll long long
#define ii pair<int, int>

using namespace std;

const int mod = 1e9 + 7;

void init(){

}

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    if(fopen("CURRENT.INP", "r")){
        freopen("CURRENT.INP", "r", stdin);
        freopen("CURRENT.OUT", "w", stdout);
    }

    init();
    solve();
}

*/
