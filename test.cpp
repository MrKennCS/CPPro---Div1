#include<iostream>
#define int long long

using namespace std;

int n, m;
int a[1005][1005];
int cnt[1000005];
int sum, id;
int res;

void loang(int x, int y){
    if(a[x][y] != 1)    return ;
    if(x < 1 || x > m)  return ;
    if(y < 1 || y > n)  return ;

    sum += 1;
    a[x][y] = id;

    loang(x, y + 1);
    loang(x, y - 1);
    loang(x + 1, y);
    loang(x - 1, y);
}

int calc(int x, int y){
    int up, dn, lt, rt;

    up = a[x - 1][y];
    dn = a[x + 1][y];
    lt = a[x][y - 1];
    rt = a[x][y + 1];

    if(up == dn)    dn = 0;
    if(up == lt)    lt = 0;
    if(up == rt)    rt = 0;
    if(dn == lt)    lt = 0;
    if(dn == rt)    rt = 0;
    if(lt == rt)    rt = 0;

    /*
    cout << "----- (" << x << ", " << y << ") -----\n";
    cout << "Up: " << x << " " << y + 1 << ": " << up << '\n';
    cout << "Do: " << x << " " << y - 1 << ": " << dn << '\n';
    cout << "Le: " << x - 1 << " " << y << ": " << lt << '\n';
    cout << "Ri: " << x + 1 << " " << y << ": " << rt << '\n';
    */

    return (cnt[up] + cnt[dn] + cnt[rt] + cnt[lt] + 1);
}
/*
6 6
1 0 1 0 1 1
1 0 1 0 1 1
1 1 1 0 0 0
0 0 0 1 1 1
1 1 0 0 1 0
1 1 1 0 1 1

6 6
1 0 0 0 1 1
1 0 0 0 1 1
1 1 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
1 1 0 0 1 1

6 6
1 1 1 0 1 1
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 0 0 0
0 1 1 0 1 0
1 1 0 0 1 1

3 3
1 1 1
1 0 1
1 1 1
*/
void solve(){
    cin >> m >> n;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            cin >> a[i][j];
        }
    }

    id = 1;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(a[i][j] == 1){
                sum = 0;
                id++;

                loang(i, j);
                cnt[id] = sum;
            }
        }
    }

    for(int i=2; i<=id; ++i)    res = max(res, cnt[i] + 1);
    for(int i=2; i<=id; ++i)    cout << cnt[i] << " ";  cout << '\n';

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(a[i][j] == 0){
                res = max(res, calc(i, j));
            }
        }
    }

    cout << res;
}

main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}
