// GIAI THICH
    /*
    Cac trang thai ta dang co la:

    n: chieu dai cua day den
    t: so thao ta can duoc thuc hien
    a: so bong den xanh can co sau khi thuc hien t buoc
    b: so bong den do can co sau khi thuc hien t buoc

    Yeu cau de: tinh so cach tao duoc mot day den n den voi a bong xanh va b bong do sau t buoc

    Ta can luu y cac trang thai:
    t: thao tac thu
    a: so bong den xanh o moi trang thai
    b: so bong den do o moi trang thai

    Goi dp[t][a][b] la so cac tao day n den co a den xanh va b den do o t buoc

    dp[0][0][0] = 1;

    Ta duyet t tang dan tu 0 -> n-1

    voi moi dp[t][a][b] ta co the cap nhat cho cac trang thai:

    TH1: dp[t+1][a+1][b]    , trang thai chuyen 1 bong tat BAT KY sang xanh 
    TH2: dp[t+1][a-1][b+1]  , trang thai chuyen 1 bong xanh BAT KY sang do
    TH3: dp[t+1][a][b-1]    , trang thai chuyen 1 bong do BAT KY sang tat

    Vi ta dang dem SO CACH, voi moi trang thai ta phai nhan vao so den o trang thai do

->  Ta co cach cap nhat o moi trang thai nhu sau:

    dp[t+1][a+1][b]     += dp[t][a][b]*(n-a-b)  , khong dieu kien
    dp[t+1][a-1][b+1]   += dp[t][a][b]*a        , a >= 1
    dp[t+1][a][b-1]     += dp[t][a][b]*b        , b >= 1
    */

// SOLUTION
/*
const int mod = 1e9 + 7;    
const int N = 606;
int n, t, a, b;
int dp[2][N][N];

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
    //if(x < mod)     x += mod;
}

void solve(){

    cin >> n >> t >> a >> b;
    dp[0][0][0] = 1;
    for(int i=0; i<t; ++i){
        int nx = (i+1)&1;
        memset(dp[nx], 0, sizeof(dp[nx]));
        for(int _a=0; _a<=min(n, i); ++_a){
            for(int _b=0; _b<=min(n-_a, i); ++_b){
                if(dp[i&1][_a][_b] > 0){
                    add(dp[nx][_a+1][_b], (1LL*dp[i&1][_a][_b]*(n-_a-_b)) % mod);
                    if(_a >= 1) add(dp[nx][_a-1][_b+1], (1LL*dp[i&1][_a][_b]*(_a)) % mod);
                    if(_b >= 1) add(dp[nx][_a][_b-1], (1LL*dp[i&1][_a][_b]*(_b)) % mod);
                }
            }
        }
    }

    cout << dp[t&1][a][b];
}
*/

/*
                                        ########## NOTE ##########

    Đề bài cho n dãy đèn từ 1 -> n

    Có t thao tác và mỗi thao tác sẽ chuyển 1 đèn thành trạng thái tiếp theo

    Tắt -> Xanh -> Đỏ (Chu kì và liên hệ giữa các đèn)

    Nhiệm vụ là tìm số cách (số trạng thái) dùng t thao tác để tạo thành 1 dãy n đèn gồm a xanh và b đỏ

    ĐẾN TRẠNG THÁI => DP

    * Ta cần quản lý những dữ liệu sau:
        + Dãy đang có bao nhiêu đèn?
        + Đã dùng bao nhiêu thao tác?
        + Đang có bao nhiêu đèn xanh?
        + Đang có bao nhiêu đèn đỏ?
        + Đang có bao nhiêu đèn tắt?

=>  dp[n - i][t - j][a - cnt_a][b - cnt_b][c - cnt_c]
=>  dp[605][605][605][605][605]

    Khai báo cnay auto chết vì tốn:
    +   ~8e13 bộ nhớ    => RTE
    +   ~8e13 thời gian => TLE

                        ---------- OPTIMIZE 1 ----------
    Ta nhận xét mỗi đèn chỉ có 3 trạng thái,
    Nx1: ta không cần chiều [c - cnt_c] vì có thể biết được bằng 2 chiều [a - cnt_a] và [b - cnt_b] bằng công thức:
    c = n - a - b

=>  dp[n - i][t - j][a - cnt_a][b - cnt_b]
=>  dp[605][605][605][605]

    Khai báo cnay auto chết vì tốn:
    +   ~8e13 bộ nhớ    => RTE
    +   ~8e13 thời gian => TLE

                        ******** CÔNG THỨC TRUY HỒI 1 ********* (Tạm thời chưa tìm dc cách để optimize thêm)
    
    MÌNH ĐANG BOTTOM UP

    dp[n][0][0][0] = 1;

    Với mỗi trạng thái, ta có 3 trường hợp:

    TH1: Chuyển 1 tắt thành xanh
=>  dp[i][j + 1][a + 1][b] += dp[i][j][a][b] * (n - a - b)

    TH2: Chuyển 1 đèn xanh thành đỏ
=>  dp[i][j + 1][a - 1][b + 1] += dp[i][j][a][b] * a

    TH3: Chuyên 1 đèn đỏ thành tắt
=>  dp[i][j + 1][a][b - 1] += dp[i][j][a][b] * b

    Từ Công thức truy hồi, ta có thể đưa tới tối ưu thứ 2

                        ---------- OPTIMIZE 2 ----------
    Nx2: Ta thấy công thức truy hồi không cần dùng đến chiều thứ n
=>  =>  dp[t - j][a - cnt_a][b - cnt_b]

                        ******** CÔNG THỨC TRUY HỒI 2 *********
    
    MÌNH ĐANG BOTTOM UP

    dp[0][0][0] = 1;

    Với mỗi trạng thái, ta có 3 trường hợp:

    TH1: Chuyển 1 tắt thành xanh
=>  dp[j + 1][a + 1][b] += dp[j][a][b] * (n - a - b)

    TH2: Chuyển 1 đèn xanh thành đỏ
=>  dp[j + 1][a - 1][b + 1] += dp[j][a][b] * a

    TH3: Chuyên 1 đèn đỏ thành tắt
=>  dp[j + 1][a][b - 1] += dp[j][a][b] * b
    
*/