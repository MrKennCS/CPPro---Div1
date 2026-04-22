#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX_N   2020
#define MAX_K   9292
const long long MOD = 20215201314LL;
void add(long long &x, long long y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int a[MAX_N], n, k, s;

void init(void) {
    cin >> n >> k >> s;
    FOR(i, 1, n) cin >> a[i];
}

namespace subtask1 {
    int b[MAX_N];
    long long res;

    int compare(int l, int r) {
        FOR(i, l, r) {
            if (a[i] < b[i]) return -1;
            if (a[i] > b[i]) return +1;
        }
        return 0;
    }

    void backtrack(int pos) {
        if (pos > n) {
            int cnt = 0;
            FOR(l, 1, n) FOR(r, l, n) if (compare(l, r) < 0) cnt++;
            if (cnt == k) res++;
            return;
        }

        for (b[pos] = 1; b[pos] <= s; b[pos]++) backtrack(pos + 1);
    }

    bool check(void) {
        return n <= 8 && s <= 4;
    }

    void solve(void) {
        backtrack(1);
        cout << res << endl;
    }
} // subtask 1

namespace subtask2 {
    int b[MAX_N];
    long long res;

    int compare(int l, int r) {
        FOR(i, l, r) {
            if (b[i] < 0) return -1;
            if (b[i] > 0) return +1;
        }
        return 0;
    }

    void backtrack(int pos) {
        if (pos > n) {
            int cnt = 0;
            FOR(l, 1, n) FOR(r, l, n) if (compare(l, r) < 0) cnt++;
            if (cnt != k) return;

            long long tmp = 1;
            FOR(i, 1, n) {
                if (b[i] < 0) tmp = tmp * (s - a[i]) % MOD;
                if (b[i] > 0) tmp = tmp * (a[i] - 1) % MOD;
            }
            res += tmp;
            if (res >= MOD) res -= MOD;

            return;
        }

        for (b[pos] = -1; b[pos] <= +1; b[pos]++) backtrack(pos + 1);
    }

    bool check(void) {
        return n <= 12;
    }

    void solve(void) {
        backtrack(1);
        cout << res << endl;
    }
} // subtask 2

namespace subtask3 {
    long long dp[100][5050][100];

    bool check(void) {
        return n <= 97;
    }

    void solve(void) {
        dp[0][0][0] = 1;

        FOR(i, 1, n) FOR(j, 0, k) FOR(t, 0, i) if (dp[i - 1][j][t] > 0) {
            // b[i] < a[i]
            dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][t] * (a[i] - 1)) % MOD;

            // b[i] = a[i]
            add(dp[i][j][t + 1], dp[i - 1][j][t]);

            // b[i] > a[i]
            int newJ = j + (t + 1) * (n - i + 1);
            if (newJ <= k) dp[i][newJ][0] = (dp[i][newJ][0] + dp[i - 1][j][t] * (s - a[i])) % MOD;
        }

        long long res = 0;
        FOR(t, 0, n) add(res, dp[n][k][t]);
        cout << res << endl;
    }
} // subtask 3

namespace subtask4 {
    bool check(void) {
        return k == 0;
    }

    int solve(void) {
        long long res = 1;
        FOR(i, 1, n) res = res * a[i] % MOD;
        cout << res << endl;
        return 0;
    }
} // subtask 4

int main(void) {
    freopen("II.INP", "r", stdin);
    freopen("II.OUT", "w", stdout);

    init();

    if (subtask1::check()) return subtask1::solve(), 0;
    if (subtask2::check()) return subtask2::solve(), 0;
    if (subtask3::check()) return subtask3::solve(), 0;
    if (subtask4::check()) return subtask4::solve(), 0;

    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
