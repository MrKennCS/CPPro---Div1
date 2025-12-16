#include<iostream>
#include<vector>

#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
/*
*/
vector<int> a, b;

void solve(int n){

    a.clear();
    b.clear();

    a.pb(0);
    b.pb(0);

    for(int i=1; i<=n; ++i) a.pb(i);

    while(sz(a) > 2){
        //for(int i=1; i<sz(a); ++i)     cout << a[i] << " ";    cout << '\n';
        for(int i=2; i<=sz(a); i+=3)    b.pb(a[i]);
        a = b;
        b.clear();
        b.pb(0);
    }
    cout << n << " " << a[1] << '\n';
}

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)   ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

void ac(){
    int n;  cin >> n;
    int res = 2;
    int mu = 1;
    while(res + binpow(3, mu) < n){
        res += binpow(3, mu);
        mu++;
    }
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    ac();
}
/*
1 3 9


1 2 3 4

2

1 2 3 4 5 6 7 8 9 10 11 12 13
2 5 8 11
5

2

3
9
27
81
...
*/