#include <bits/stdc++.h>
using namespace std;

// Tính C(2k, k) / (k+1) an toàn bằng phép nhân/chia dần
unsigned long long catalan(int k) {
    if (k <= 1) return 1;
    // Tính binomial C(2k, k) bằng cách nhân-chia từng bước để tránh overflow nhiều
    unsigned long long res = 1;
    for (int i = 1; i <= k; ++i) {
        // res *= (k + i) / i   (tính C(2k,k) = Π_{i=1..k} (k+i)/i)
        // nhưng làm theo dạng res = res * (k+i) / i, chia từng bước (chia phải chia vì chia tận cùng chia đều)
        res = res * (k + i) / i;
    }
    // rồi chia (k+1) để được Catalan
    return res / (k + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    if (n % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    int k = n / 2;
    cout << catalan(k) << '\n';
    return 0;
}
