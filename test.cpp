#include <iostream>
#include <chrono> // Thư viện bắt buộc để đo thời gian

using namespace std;
using namespace std::chrono;

void solve() {
    // Giả lập một thuật toán chạy tốn thời gian
    long long sum = 0;
    for (int i = 0; i < 100000000; i++) {
        sum += i;
    }
    cout << "Ket qua: " << sum << endl;
}

int main() {
    // 1. Bắt đầu đo
    auto start = high_resolution_clock::now();

    solve();

    // 2. Kết thúc đo
    auto stop = high_resolution_clock::now();

    // 3. Tính toán khoảng cách thời gian
    // Ở đây mình dùng duration<double> để lấy số lẻ (giây)
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "-----------------------------" << endl;
    cout << "Thoi gian chay: " << duration.count() << " ms" << endl;
    
    return 0;
}