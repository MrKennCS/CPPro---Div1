#include<iostream>
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

int n, k;
int dp[10005];

/*
Goi dp[i] la so truong hop khong thoa

1100

0110
1110

0011
1011
0111
1111
1101

    1 2 3 4
    2 3

    1:
    0
    1

    2:
    00
    01
    10
    11

    3:
    000
    010
    100
    110
    001
    011
    101
    
    4:
    0000
    0100
    1000
    1100
    0010
    0110
    1010

    0001
    0101
    1001
    1101
    0011
    011
    1011

0000
1000
0100
0010
1010
0001
1001
0101

000
100
010
101
001

110
011
111
*/

void gen(){
    cin >> n >> k;
    int res = 0;
    int cnt;

    for(int mask=0; mask<(1LL<<n); ++mask){
        cnt = get_bit(mask, 0);
        for(int i=1; i<n; ++i){
            if(get_bit(mask, i))    cnt++;
            else{
                if(cnt >= k)    res++;
                cnt = 0;
            }
            //cout << get_bit(mask, i);
        }
        //cout << '\n';
    }

    cout << res;
}

void solve(){
    cin >> n >> k;
    dp[k] = 1;
    for(int i=k+1; i<=n; ++i){

    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    gen();
}