#include<iostream>
#include<set>
using namespace std;

// SOLUTION VARIABLES
/*
const int mod = 1e9 + 7;
int n;
int tong;
int cnt;
int x[105];
int dp[103][100005];
int DP[100005];
*/

// SOLUTION EXPLAIN
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

// BOTTOM UP SOLUTION
/*
void bottomup(){
    // ----- START OF CODE - EXPLAINATION -----
*   BOTTOM UP:

    Với mỗi trạng thái i, ta có 2 trường hợp:

    TH1: Chọn i
    (i, sum) -> (i+1, sum + x[i])
->  dp[i+1][sum + x[i]] = max(dp[i][s], dp[i+1][sum + x[i]])

    TH2: Không chọn i
->  (i, sum) -> (i+1, sum)
=>  dp[i+1][sum] = max(dp[i+1][sum], dp[i][sum])
    
    // ----- END OF CODE - EXPLAINATION -----
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

    for(int i=1; i<=tong; ++i)  if(dp[n][i] == 1)   cnt++;

    cout << cnt << '\n';
    for(int i=1; i<=tong; ++i)  if(dp[n][i] == 1){
        cout << i << " ";
    }
}
*/

// TOP DOWN SOLUTION
/*
void topdown(){
    // ----- START OF CODE - EXPLAINATION -----
    
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
    
    // ----- END OF CODE - EXPLAINATION -----
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

    for(int i=1; i<=tong; ++i) if(dp[n][i] == 1)    cnt++;
    cout << cnt << '\n';
    for(int i=1; i<=tong; ++i)  if(dp[n][i] == 1){
        cout << i << " ";
    }
}
*/

// TOI UU CHIEU TOP DOWN SOLUTION
/*
void toiuu_topdown(){
    // ----- START OF CODE - EXPLAINATION -----
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
    // ----- END OF CODE - EXPLAINATION -----

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
    }

    // ----- NHAP -----
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
    // ----- END -----

    for(int sum=1; sum<=tong; ++sum)    if(DP[sum] == 1)    cnt++;
    cout << cnt << '\n';
    for(int sum=1; sum<=tong; ++sum)    if(DP[sum] == 1){
        cout << sum << " ";
    }
}
*/

int n;
int x[105];
bool dp[105][100005];
set<int> st;
/*
4
4 2 5 2
*/
void review(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> x[i];

    dp[0][0] = true;
    for(int i=0; i<n; ++i){
        for(int sum=0; sum<=100000; ++sum){
            if(dp[i][sum]){
                dp[i + 1][sum + x[i + 1]] = dp[i][sum];
                dp[i + 1][sum] = dp[i][sum];
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int sum=1; sum<=100000; ++sum){
            if(dp[i][sum])  st.insert(sum);
        }
    }

    cout << (int)st.size() << '\n';
    for(set<int>::iterator it=st.begin(); it!=st.end(); ++it)   cout << (*it) << " ";
}

int lim;
bool dp1[100005];

void review_toiuu1(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> x[i];
        //dp1[x[i]] = true;
        lim += x[i];
    }

    dp1[0] = true;
    for(int i=0; i<n; ++i){
        //dp1[x[i + 1]] = true;
        for(int sum=lim; sum>=x[i+1]; --sum){
            if(dp1[sum - x[i + 1]])    dp1[sum] = dp1[sum - x[i + 1]];
        }
        //for(int sum=1; sum<=lim; ++sum) cout << dp1[sum] << " "; cout << '\n';   
    }

    int cnt = 0;
    for(int i=1; i<=lim; ++i)   if(dp1[i])   cnt++;
    cout << cnt << '\n';
    for(int i=1; i<=lim; ++i)   if(dp1[i])  cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //bottomup();
    //topdown();
    //toiuu_topdown();
    review_toiuu1();
}
