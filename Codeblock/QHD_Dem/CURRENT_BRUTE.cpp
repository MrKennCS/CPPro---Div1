#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a; i>=b; --i)
#define getbit(x, y) (((x) >> (y)) & 1)
#define sz(a) (int)a.size()
#define ll long long
#define ii pair<int, int>

using namespace std;

const int mod = 1e9 + 7;

int n;
double a[3003];

void init(){
    cin >> n;
    FORU(i, 1, n)   cin >> a[i];
}

namespace trau{
    double res = 0;

    bool check(){
        if(n <= 20) return true;
        return false;
    }

    void solve(){
        FORU(mask, 0, (1<<n)-1){
            int cnt = 0;
            double cur = 1;
            FORU(i, 0, n-1){
                if(getbit(mask, i)){
                    cnt++;
                    cur *= a[i + 1];
                }else   cur *= (1 - a[i + 1]);
            }
            if(cnt > n/2)   res += cur;
        }
        cout << fixed << setprecision(9) << res;
    }
}

namespace chuan{
    double dp[3003][3003];
    double res = 0;

    bool check(){
        if(n <= 100)    return true;
        return false;
    }

    void solve(){
        dp[1][0] = 1 - a[1];
        dp[1][1] = a[1];
        FORU(i, 2, n){
            FORU(cnt, 0, n){
                dp[i][cnt] = dp[i - 1][cnt] * (1 - a[i]);
                if(cnt > 0) dp[i][cnt] += dp[i - 1][cnt - 1] * a[i];
            }
        }

        FORU(i, n/2+1, n)   res += dp[n][i];

        cout << fixed << setprecision(9) << res;
    }
}

void solve(){
    if(trau::check())   return trau::solve();
    //if(chuan::check())  return chuan::solve();
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
