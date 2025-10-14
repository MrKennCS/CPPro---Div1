#include <bits/stdc++.h>

using namespace std;

unsigned long long catalan(int k) {
    if (k <= 1) return 1;
    unsigned long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (k + i) / i;
    }
    return res / (k + 1);
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(0);

    int n;  cin >> n;

    cout << catalan(n/2);
}
