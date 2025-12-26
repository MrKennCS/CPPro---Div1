#include<iostream>
#include<cstring>
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

/*
    Đề bài cho xâu q xâu s, nhiệm vụ là đếm số xâu con của xâu s là PALINDROM

    Nghĩ thử nếu giải theo trạng thái, ta sẽ làm như thế nào?
*/

// SOLUTION
/*
int q, m, n;
string s;
int res;
int dp[205][205];

void add(int &x, int y){
    x += y;
    if(x >= m)  x -= m;
}

void trau(){
    cin >> m;

    while(cin >> s){
        //cin >> s;
        res = 0;

        for(int mask=0; mask<(1LL<<sz(s)); ++mask){
            string tmp = "";
            //cout << "---\n";
            for(int i=0; i<sz(s); ++i){
                if(get_bit(mask, i)){
                    tmp += s[i];
                }
            }
            //cout << tmp << '\n';
            int l = 0;
            int r = sz(tmp)-1;
            bool valid = true;
            while(l <= r){
                if(tmp[l] != tmp[r]){
                    valid = false;
                    break;
                }
                l++;
                r--;
            }
            add(res, valid);
        }

        cout << res << '\n';
    }
}

void solve(){
    cin >> m;
    string tmp;
    while(cin >> tmp){
        //string tmp; cin >> tmp;
        s = " " + tmp;
        n = sz(tmp);

        // BASE
        for(int i=1; i<=n; ++i) dp[i][i] = 1;

        for(int i=n-1; i>=1; --i){
            for(int j=i+1; j<=n; ++j){
                //dp[i][j] += dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                //if(s[i] == s[j])    dp[i][j] += (dp[i + 1][j - 1] + 1);
                add(dp[i][j], (1LL * dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + m) % m);
                if(s[i] == s[j])    add(dp[i][j], (1LL * dp[i + 1][j - 1] + 1) % m);
            }
        }

        cout << dp[1][n] + 1 << '\n';

        memset(dp, 0, sizeof(dp));
    }
}
*/

const int N = 202;
int m, q, n;
string s;
string inp;
int dp[205][205];
/*
    Làm sao để đếm số cách thỏa mãn?

    Gọi dp[l][r] là số xâu thỏa mãn

    dp[i][i] = 1

    for(int i=n-1; i>=1; --i){
        for(int j=i+1; j<=n; ++j){
            dp[i][j] += (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]);
            if(s[i] == s[j])    dp[i][j] += dp[i + 1][j - 1];
        }
    }
*/

void add(int &x, int y){
    x += y;
    if(x >= m)  x -= m;
}

void review(){
    cin >> m;

    while(cin >> inp){
        //cin >> inp;
        if(inp == "")   return;
        s = " " + inp;
        n = sz(inp);
        
        for(int i=1; i<=n; ++i)   dp[i][i] = 1;

        for(int i = n - 1; i >= 1; --i){
            for(int j = i + 1; j <= n; ++j){
                add(dp[i][j], (1LL * dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + 1) % m);
                //dp[i][j] += (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]);
                if(s[i] == s[j])    add(dp[i][j], (1LL * dp[i + 1][j - 1] + 1) % m);
            }
        }
        
        //cout << "---\n";
        add(dp[1][n], 1);
        cout << dp[1][n] << '\n';

        /*
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
        */

        memset(dp, 0, sizeof(dp));
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    //trau();
    //palin();
    review();
}