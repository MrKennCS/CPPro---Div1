#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

long long randInt(long long l, long long r) {
    long long res = 0;
    FOR(i, 1, 4) res = (res << 15) ^ (rand() & ((1 << 15) - 1));
    return l + res % (r - l + 1);
}

int main(void) {
    freopen("II.INP", "w", stdout);

    srand(time(nullptr));

    int n = randInt(5, 8);
    int s = randInt(3, 4);
    int k = randInt(0, n * (n + 1) / 2);

    cout << n << " " << k << " " << s << endl;
    cerr << n << " " << k << " " << s << '\n';
    FOR(i, 1, n){
        long long tmp = randInt(1, s);
        cout << tmp << " ";
        cerr << tmp << " ";
    }
    cout << endl;

    return 0;
}
