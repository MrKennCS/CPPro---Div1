#include<iostream>
#include<vector>

using namespace std;

int n, m;
int T;
int a[505][505];
int pre[505][505];
vector<vector<pair<int, int>>> id(505, vector<pair<int, int>>(505, {0, 0}));
int q, R, D, x, y, x1, y1;
int sum_r, sum_d;
int res;

void truyvan(){
    cin >> q;
    if(q == 0){
        // NX1: Khi sum_r % m == 0 thi bang khong thay doi ve thu tu cot
        //      Khi sum_d % n == 0 thi bang khong thay doi ve thu tu hang
        cin >> R >> D;
        sum_r += R;
        sum_d += D;
    }else{
        cin >> x >> y >> x1 >> y1;
        /*
        -> Cong thuc doi vi tri moi sau moi truy van 0 la:
                x += D
                y -= R
        */
        sum_r %= m;
        sum_d %= n;

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                int new_x = (id[i][j].first + sum_d > n  ? id[i][j].first + sum_d - n  : id[i][j].first + sum_d );
                int new_y = (id[i][j].second - sum_r < 1 ? id[i][j].second - sum_r + m : id[i][j].second - sum_r);
                id[i][j] = {new_x, new_y};
                //cout << id[i][j].first << "-" << id[i][j].second << " | "; 
            }
            //cout << '\n';
        }

        sum_r = 0;
        sum_d = 0;

        res = 0;
        for(int i=x; i<=x1; ++i){
            for(int j=y; j<=y1; ++j){
                cout << a[id[i][j].first][id[i][j].second] << " ";
                res += a[id[i][j].first][id[i][j].second];
            }
            cout << '\n';
        }
        cout << "Res: " << res << '\n';
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
            id[i][j] = {i, j};
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
            //cout << id[i][j].first << "-" << id[i][j].second << " | "; 
        }
        //cout << '\n';
    }

    cin >> T;
    while(T--){
        truyvan();
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}

/*
TEST1:
4 5
1 2 5 2 1   
4 3 1 2 3
2 3 5 3 1
3 2 1 1 5
5
0 2 1
1 2 2 3 4
0 2 4
1 1 1 1 1
1 3 2 4 5

TEST2:
4 5
1 2 5 2 1   
4 3 1 2 3
2 3 5 3 1
3 2 1 1 5
3
1 2 2 3 4
1 1 1 1 1
1 3 2 4 5

5 2 1 1 2   
1 2 3 4 3
5 3 1 2 3
1 1 5 3 2

1 2 3 4 3
5 3 1 2 3
1 1 5 3 2
5 2 1 1 2

TEST:
3 4
1  2  3  4
5  6  7  8
9 10 11 12
2
0 2 1
1 1 1 1 1

1  2  3  4      (1, 1)  (1, 2)  (1, 3)  (1, 4)
5  6  7  8      (2, 1)  (2, 2)  (2, 3)  (2, 4)
9 10 11 12      (3, 1)  (3, 2)  (3, 3)  (3, 4)

1 2 2 3 4   -> 54

R = 2
D = 1


 7  8  5  6     (2, 3)  (2, 4)  (2, 1)  (2, 2)
11 12  9 10     (3, 3)  (3, 4)  (3, 1)  (3, 2)
 3  4  1  2     (1, 3)  (1, 4)  (1, 1)  (1, 2)

(2, 2) = (3, 4)
(2, 3) = (3, 1)
(2, 4) = (3, 2)
(3, 2) = (1, 4)

-> Cong thuc doi vi tri moi sau moi truy van 0 la:

                x += D
                y -= R
*/