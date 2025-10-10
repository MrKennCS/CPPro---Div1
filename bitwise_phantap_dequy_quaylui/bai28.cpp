#include<iostream>
#define ll long long
#define get_bit(x, y) (((x) >> (y)) & 1)
using namespace std;

int n;
int a[25];
ll sum;
ll check;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    if(sum & 1){
        cout << -1;
        return ;
    }

    // 2097153 ~ 2e6

    check = sum / 2;
    sum = 0;

    int end = (1 << (n+1)) + 1;

    for(int i=0; i<=end; ++i){
        for(int j=0; j<n; ++j){
            if(get_bit(i, j) == 1)  sum += (a[j]);
        }
        if(sum == check){
            for(int j=0; j<n; ++j){
                cout << get_bit(i, j);
            }
            cout << '\n';        
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}