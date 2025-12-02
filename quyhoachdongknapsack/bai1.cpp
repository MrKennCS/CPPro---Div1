#include<iostream>

using namespace std;

int n, c;
int w[20];
int dp[5005];

void solve(){
    cin >> c >> n;
    for(int i=1; i<=n; ++i) cin >> w[i];

    /*
    Goi dp[i] la co cach nao de tao ra mot day co tong bang i hay khong, luu y day nay gom cac phan tu cua w[i] phan biet nhau

    VD:

    8 4
    2 3 3 4

    dp[2]
    */
    dp[0] = 1;
    for(int i=1; i<=n; ++i){
        //cout << "VERSION: " << i << '\n';
        for(int x=c; x>=w[i]; --x){
            if(dp[x - w[i]] == 1){
                //cout << "Update: " << x << " " << 1 << '\n';
                dp[x] = 1;
            }
        }
    }

    for(int i=c; i>=1; --i) if(dp[i] == 1){
        cout << i;
        return ;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}