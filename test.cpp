#include <iostream>
#include <bitset>

using namespace std;

const int LIM = 100000000; // 10^8
bitset<LIM + 5> is_prime; // Mặc định tất cả là 0

void sieve() {
    is_prime.set(); // Đặt tất cả các bit thành 1 (coi như đều là số nguyên tố)
    is_prime[0] = is_prime[1] = 0; // 0 và 1 không phải SNT

    for (int i = 2; 1LL * i * i <= LIM; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIM; j += i) {
                is_prime.reset(j); // Đặt bit thứ j thành 0 cực nhanh
            }
        }
    }
}

int main() {
    sieve();
    if (is_prime[97]) cout << "97 la so nguyen to!";
    
    // Đếm xem có bao nhiêu số nguyên tố từ 0 đến LIM
    cout << "\nSo luong SNT: " << is_prime.count(); 
    return 0;
}