#include<iostream>
#include<unordered_map>

using namespace std;

int q;
int x, y;

void solve(){
    cin >> q;
    /*
    1  2  3  4  5

1   1  2  9 10 25
2   4  3  8 11 24
3   5  6  7 12 23
4  16 15 14 13 22
5  17 18 19 20 21

    TEST x == y

    5
    1 1
    2 2
    3 3
    4 4
    5 5

    */

    while(q--){
        cin >> x >> y;

        int mx = max(x, y);
        long long mid = 1LL * mx * mx - mx + 1;
        
        if(x == y){
            cout << mid;
        }else if(x > y){
            int diff = x - y;
            if(x & 1)   cout << mid - diff;
            else        cout << mid + diff;
        }else if(x < y){
            int diff = y - x;
            if(y & 1)   cout << mid + diff;
            else        cout << mid - diff;
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}