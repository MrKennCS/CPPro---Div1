#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
int n;
int tong;
int cnt;
int x[105];
int dp[103][100005];
int DP[100005];

/*
    có n đồng xu, tìm các khoản tiền có thể tạo bằng những đồng xu này

    Lưu ý:
    + Mỗi một đồng xu chỉ được phép dùng một lần

->  Bài toán này không yêu cầu đếm số trạng thái
    Nhưng nếu ta suy nghĩ theo hướng QHĐ thử:

    Ta cần quản lý 2 thứ:
    
    Trạng thái cơ sở: [i] là đồng xu ta đang xét
->  Để thỏa điều kiện đề bài, ta sẽ duyệt mỗi đồng xu i: 1 -> n

    Liên tưởng đến bitset, ta chỉ cần tạo ra tất cả các trường hợp (0011010011 ...) và cộng mỗi giá trị 1 lại
    Nhưng n <= 100 nên không thể dùng cách này (TLE)

    Như vậy ta thấy ta cần duyệt tất cả trạng thái của bài toán
->  Khi này DP sẽ hợp lý

    CONTINUE:
    Với mỗi trạng thái i của bài toán, ta cần lưu ý đến tổng của trạng thái đó
->  Ta sẽ thêm một chiều là sum (sum: 1 -> tong), với 'tong' là tổng x[1->n]

->  dp[i][sum] là trạng thái của bài toán

    BASE:
    dp[0][0] = 1
*/

void bottomup(){
    /*
*   BOTTOM UP:

    Với mỗi trạng thái i, ta có 2 trường hợp:

    TH1: Chọn i
    (i, sum) -> (i+1, sum + x[i])
->  dp[i+1][sum + x[i]] = max(dp[i][s], dp[i+1][sum + x[i]])

    TH2: Không chọn i
->  (i, sum) -> (i+1, sum)
=>  dp[i+1][sum] = max(dp[i+1][sum], dp[i][sum])
    */
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> x[i];
        tong += x[i];
    }

    dp[0][0] = 1;

    for(int i=0; i<n; ++i){
        for(int sum=0; sum<=tong; ++sum){
            dp[i+1][sum] = max(dp[i][sum], dp[i+1][sum]);
            dp[i+1][sum + x[i+1]] = max(dp[i + 1][sum + x[i+1]], dp[i][sum]);
        }
    }
    /*
    
    for(int sum=0; sum<=tong; ++sum)    dp[0][sum] = sum;
    for(int i=0; i<=n; ++i)             dp[i][0] = i;
    dp[0][0] = 1;

    for(int sum=0; sum<=tong; ++sum){
        for(int i=0; i<=n; ++i){
            cout << dp[i][sum] << " ";
        }
        cout << '\n';
    }
    */

    for(int i=1; i<=tong; ++i)  if(dp[n][i] == 1)   cnt++;

    cout << cnt << '\n';
    for(int i=1; i<=tong; ++i)  if(dp[n][i] == 1){
        cout << i << " ";
    }
}

void topdown(){
    /*
    Ta thấy với mỗi trạng thái i, ta có 2 trường hợp chọn hoặc không chọn i
    Tức là khi lên trạng thái i, ta ĐÃ PHẢI DUYỆT 2 TRẠNG THÁI i-1 mà tại đó có 2 trường hợp i-1 được chọn và ko được chọn

->  dp[i][sum] = max(dp[i-1][sum], dp[i-1][sum - x[i]])

    Như vậy, ta sẽ duyệt qua từng i: 1 -> n

    Với s, do sum - x[i] có thể âm nên ta lưu ý một chút

    for(int i=1; i<=n; ++i) dp[i][0] = 1
    for(int i=1; i<=n; ++i){
        for(int s=x[i]; s<=tong; ++s){
            dp[i][s] = max(dp[i-1][s], dp[i-1][s-x[i]])
        }
    }
    */
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> x[i];
        tong += x[i];
    }

    for(int i=0; i<=n; ++i) dp[i][0] = 1;
    for(int i=1; i<=n; ++i){
        for(int sum=1; sum<x[i]; ++sum) dp[i][sum] = dp[i-1][sum];
        for(int sum=x[i]; sum<=tong; ++sum){
            dp[i][sum] = max(dp[i-1][sum], dp[i-1][sum - x[i]]);
            //dp[i][sum] = max(dp[i][sum], dp[i-1][sum]);
        }
    }

    /*
    for(int sum=0; sum<=tong; ++sum)    dp[0][sum] = sum;
    for(int i=0; i<=n; ++i)             dp[i][0] = i;
    dp[0][0] = 1;

    for(int sum=0; sum<=tong; ++sum){
        for(int i=0; i<=n; ++i){
            cout << dp[i][sum] << " ";
        }
        cout << '\n';
    }
    */

    for(int i=1; i<=tong; ++i) if(dp[n][i] == 1)    cnt++;
    cout << cnt << '\n';
    for(int i=1; i<=tong; ++i)  if(dp[n][i] == 1){
        cout << i << " ";
    }
}

void toiuu_topdown(){
    /*
    Vay ta co the giam chieu khong?
->  Co, tai sao?

    Để ý thấy với mỗi trạng thái i, ta luôn phải cập nhật giá trị trước đó qua, ta có thể giảm bớt điều này nếu bỏ luôn kiểu cập nhật này
    và để mảng 1 chiều

->  dp[sum]
    Vậy ta sẽ tư duy như thế nào?

    Khi không duyệt chiều trạng thái i nữa, để thỏa mãn mỗi đồng xu chỉ được chọn duy nhất một lần thì ta phải duyệt ngược sum
->  sum: tong -> 1

    MÃ GIẢ:

    dp[0] = 1;
    for(int i=1; i<=n; ++i){
        for(int sum=tong; sum>=1; --sum){
            dp[sum] = max(dp[sum], dp[sum - x[i]])
        }
    }

    */

    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> x[i];
        tong += x[i];
    }

    DP[0] = 1;
    for(int i=1; i<=n; ++i){
        for(int sum=tong; sum>=x[i]; --sum){
            DP[sum] = max(DP[sum], DP[sum - x[i]]);
        }
        /*
        cout << "TRUONG HOP I = " << i << '\n'; 
        for(int sum=1; sum<=tong; ++sum){
            for(int j=1; j<=2; ++j){
                if(j == 1)  cout << sum << " ";
                else        cout << DP[sum] << '\n';
            }
        }
        */
    }

    /*
1 1 2 3 4 
1 0 0 0 0
2 0 1 1 1
3 0 0 0 0
4 1 1 1 1
5 0 0 1 1
6 0 1 1 1
7 0 0 1 1
8 0 0 0 1
9 0 0 1 1
10 0 0 0 0
11 0 0 1 1
12 0 0 0 0
13 0 0 0 1
    */

    for(int sum=1; sum<=tong; ++sum)    if(DP[sum] == 1)    cnt++;
    cout << cnt << '\n';
    for(int sum=1; sum<=tong; ++sum)    if(DP[sum] == 1){
        cout << sum << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //bottomup();
    //topdown();
    toiuu_topdown();
}