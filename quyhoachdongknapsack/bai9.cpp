/*
WARNING: ĐÂY LÀ CODE 100% DO AI TẠO RA
MỤC ĐÍCH SUBMIT CODE LÀ ĐỂ DEBUG VÀ RÚT KINH NGHIỆM, KHÔNG MANG MỤC ĐÍCH SUBMIT LẤY ĐIỂM QUA BÀI
*/

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    // Tối ưu hóa I/O trong C++ để đọc/ghi nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    // Khởi tạo mảng DP
    vector<long long> dp(k + 1, 0);
    dp[0] = 1; // Có 1 cách để tạo ra tổng 0

    for (int i = 0; i < n; ++i) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            // Thao tác thêm: Duyệt ngược
            for (int j = k; j >= x; --j) {
                dp[j] = (dp[j] + dp[j - x]) % MOD;
            }
        } else if (op == '-') {
            // Thao tác xóa: Duyệt xuôi
            for (int j = x; j <= k; ++j) {
                // Cộng thêm MOD trước khi chia lấy dư để tránh số âm trong C++
                dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
            }
        }
        
        // In ra kết quả sau mỗi thao tác
        cout << dp[k] << "\n";
    }

    return 0;
}
