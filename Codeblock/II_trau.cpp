#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   2222
int a[MAX], b[MAX], n, k, s, res;

int compare(int l, int r) {
    FOR(i, l, r) if (a[i] != b[i]) return a[i] > b[i] ? 1 : -1;
    return 0;
}

void backtrack(int i) {
    if (i > n) {
        int cnt = 0;
        FOR(i, 1, n) FOR(j, i, n) if (compare(i, j) < 0) cnt++;
        if (cnt == k) {
            res++;
//            FOR(i, 1, n) printf("%d ", b[i]); printf("\n");
        }
        return;
    }

    for (b[i] = 1; b[i] <= s; b[i]++) backtrack(i + 1);
}

int main(void) {
    freopen("II.INP", "r", stdin);
    freopen("II.ANS", "w", stdout);

    cin >> n >> k >> s;
    FOR(i, 1, n) cin >> a[i];
    backtrack(1);
    cout << res << endl;

    cerr << res << endl;
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
