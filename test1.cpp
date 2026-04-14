#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int xor_sum = 0;
        
        // XOR tất cả các số từ 1 đến n
        for (int i = 1; i <= n; i++) {
            xor_sum ^= i;
        }
        
        // XOR với các số trong input
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            xor_sum ^= x;
        }
        
        cout << xor_sum << "\n";
    }
    return 0;
}