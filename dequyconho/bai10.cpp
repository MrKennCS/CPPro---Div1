#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

int dp[5005][5005];

int a[200005], n, k;

void sub1_2() {
    dp[1][1] = 1;

    for(int i = 1; i < n; i++) {
        for(int cnt = 1; cnt <= min(i, k); cnt++) {
            // i + 1 di len 1 nhom moi

            dp[i + 1][1] = (dp[i + 1][1] + dp[i][cnt]) % mod;

            // i + 1 vao chung nhom voi i
            if(a[i] == a[i + 1] && cnt + 1 <= k) {
                dp[i + 1][cnt + 1] = (dp[i + 1][cnt + 1] + dp[i][cnt]) % mod;
            }
        }
    }

    int res = 0;
    for(int cnt = 1; cnt <= k; cnt++) res = (res + dp[n][cnt]) % mod;

    cout << res;
}

int f[200005];
int sum[200005];

//sum[i] = f[0] + f[1] + f[2] + ... + f[i]

int get(int l, int r) {
    if(l == 0) return sum[r];
    return (sum[r] - sum[l - 1] + mod) % mod;
}

void sub_ac() {
    f[0] = f[1] = 1;

    sum[0] = 1;
    sum[1] = 2;

    int pos = 1;

    for(int i = 2; i <= n; i++) {

        if(a[i] != a[i - 1]) {
            f[i] = f[i - 1];
            pos = i;
        }
        else {
            int L = max(pos, i - k + 1) - 1;

            f[i] = get(L, i - 1);
        }
        sum[i] = (sum[i - 1] + f[i]) % mod;
    }

    cout << f[n];
}

int main() {

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> k;
    
    if(n <= 5000) {
        sub1_2();
    }
    else {
        sub_ac();
    }

}
