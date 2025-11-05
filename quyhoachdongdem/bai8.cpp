#include<iostream>
#include<cstring>

#define sz(a) (int)a.size()
using namespace std;

int m;
string s;
int dp[205][205];
int res;
int q;

void add(int &x, int y){
    x += y;
    if(x >= m)  x -= m;
}

void solve(){
    /*
    Ta co cac trang thai:

    TU duy: dem voi moi 

100 
2
a 
ab 

010
101
110
011


    */

    cin >> m >> q;

    while(q--){
        cin >> s;
        for(int i=0; i<sz(s); ++i){
            int l, r;
            l = r = i;
            dp[l][r] = 1;
            while(l-1 >= 0 && r+1<sz(s)){
                if(s[l-1] == s[r+1]){
                    add(dp[l-1][r+1], dp[l][r] + 1);
                    //dp[l-1][r+1] += (dp[l][r] + 1);
                    l--;
                    r++;
                }else   break;
            }
            add(res, dp[l][r]);
            //res += dp[l][r];
            l = i;
            r = i + 1;
            if(r == sz(s))  break;
            memset(dp, 0, sizeof(dp));
            if(s[l] == s[r]){
                while(l-1 >= 0 && r+1<sz(s)){
                    if(s[l-1] == s[r+1]){
                        add(dp[l-1][r+1], dp[l][r] + 1);
                        //dp[l-1][r+1] += (dp[l][r] + 1);
                        l--;
                        r++;
                    }else   break;
                }
            }
            add(res, dp[l][r]);
        }
        add(res, 1);
        cout << res << '\n';
        memset(dp, 0, sizeof(dp));
        res = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}