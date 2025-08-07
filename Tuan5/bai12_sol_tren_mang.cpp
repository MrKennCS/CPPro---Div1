#include <iostream>
#include <vector>
#include <algorithm>

// Hàm giải quyết bài toán
void solve() {
    // ---- Bước 1: Đọc dữ liệu đầu vào ----
    int M, N, K;
    std::cin >> M >> N >> K;

    std::vector<int> a(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> a[i];
    }

    // ---- Bước 2: Sắp xếp mảng điểm xinh đẹp ----
    std::sort(a.begin(), a.end());

    // ---- Bước 3: Tính mảng tiền tố ----
    // Sử dụng long long để tránh tràn số khi tính tổng
    std::vector<long long> prefix_sum(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    // ---- Bước 4: Thuật toán cửa sổ trượt ----
    long long max_sum = -2; // Khởi tạo kết quả là -2
    int left = 0; // Con trỏ trái của cửa sổ

    // Di chuyển con trỏ phải để duyệt qua các cửa sổ
    for (int right = 0; right < M; ++right) {
        // Nếu cửa sổ hiện tại không hợp lệ (hiệu > K), co cửa sổ từ bên trái
        while (a[right] - a[left] > K) {
            left++;
        }

        // Tại đây, cửa sổ [left, right] là hợp lệ.
        // Kiểm tra xem nó có đủ N người không.
        if (right - left + 1 >= N) {
            // Nếu đủ, ta có một nhóm ứng viên.
            // Để tổng lớn nhất, chọn N người có điểm cao nhất trong cửa sổ này.
            // Đó là các phần tử từ chỉ số (right - N + 1) đến right.
            
            // Tính tổng của N người này bằng mảng tiền tố.
            // Tổng a[i]...a[j] = prefix_sum[j+1] - prefix_sum[i]
            long long current_sum = prefix_sum[right + 1] - prefix_sum[right - N + 1];

            // Cập nhật tổng lớn nhất tìm được
            if (max_sum == -2) { // Nếu đây là nhóm hợp lệ đầu tiên
                max_sum = current_sum;
            } else {
                max_sum = std::max(max_sum, current_sum);
            }
        }
    }

    // ---- Bước 5: In kết quả ----
    std::cout << max_sum << std::endl;
}

int main() {
    // Tăng tốc độ nhập xuất
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}