#include<bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng);
}

int n;

void init(){
    cin >> n;
}

namespace sub1{
    bool check(){
        return (n <= 10);
    }

    void solve(){
        cout << Rand(1, 100);
    }
}

namespace sub2{
    bool check(){
        return (n <= 100);
    }
    void solve(){
        cout << Rand(101, 1000);
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    init();

    if(sub1::check())   return sub1::solve(), 0;
    if(sub2::check())   return sub2::solve(), 0;
}
