#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a; i>=b; --i)
#define getbit(x, y) (((x) >> (y)) & 1)

using namespace std;

const int mod = 1e9 + 7;

int n, k;
int h[1003];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

namespace sub1{
    int Pow[12];
    int res;

    bool check(){
        if(n <= 10){
//            int valid = true;
//            for(int i=1; i<=k; ++i) if(h[i] > n)    valid = false;
//            return valid;
            return true;
        }else   return false;
    }

    int trau(int x){
        if(x < 0)   return 0;
        if(x == 0)  return 1;

        int res = 0;

        for(int i=1; i<=k; ++i) add(res, trau(x - h[i]));

        return res;
    }

    void solve(){
        //cout << "SUB1\n";
        cout << trau(n);
    }
}

namespace sub2{
    int dp[10004];

    bool check(){
        if(n <= 10000 && k == 3){
            int valid1 = true;
//            int valid2 = true;
            sort(h + 1, h + 4);
            for(int i=1; i<=3; ++i){
                if(h[i] != i)   valid1 = false;
                //if(h[i] > n)    valid2 = false;
            }
            return (valid1);
        }else   return false;
    }

    void solve(){
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; ++i){
            add(dp[i], dp[i - 1]);
            add(dp[i], dp[i - 2]);
            add(dp[i], dp[i - 3]);
        }

        cout << dp[n];
    }
}

namespace sub3{
    int dp[100005];
    bool check(){
        if(n <= 100000 && k <= 1000){
//            bool valid1 = true;
//            FORU(i, 1, k)   if(h[i] > n)    valid1 = false;
//            return valid1;
            return true;
        }else   return false;
    }
    void solve(){
        //cout << "SUB3\n";
        dp[0] = 1;

        FORU(i, 1, n){
            FORU(j, 1, k){
                if(i - h[j] >= 0){
                    add(dp[i], dp[i - h[j]]);
                }
            }
        }

        cout << dp[n];
    }
}

void init(){
    cin >> n >> k;
    FORU(i, 1, k)   cin >> h[i];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //freopen("CURRENT.INP", "r", stdin);
    //freopen("CURRENT.OUT", "w", stdout);

    init();

    if(sub1::check())   return sub1::solve(), 0;
    if(sub2::check())   return sub2::solve(), 0;
    if(sub3::check())   return sub3::solve(), 0;
}
/*
#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a; i>=b; --i)
#define getbit(x, y) (((x) >> (y)) & 1)

using namespace std;

const int mod = 1e9 + 7;

int n, t, A, B;

void init(){
    cin >> n >> t >> A >> B;
}

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

namespace sub1{
    bool check(){
        return (n <= 6 && t <= 6);
    }

    int trau(int i, int a, int b){
        if(t == 0)          return 1;
        if(a < 0 || b < 0)  return 0;

        int res = 0;

        add(res, trau(i - 1, a - 1, b));
        add(res, trau(i - 1, a + 1, b - 1));
        add(res, trau(i - 1, a, b + 1));

        return res;
    }
    void solve(){
        cout << trau(t, A, B);
    }
}

namespace sub2{

}

namespace sub3{

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    freopen("CURRENT.INP", "r", stdin);
    freopen("CURRENT.OUT", "w", stdout);

    init();

    if(sub1::check())   sub1::solve(), 0;
}

*/