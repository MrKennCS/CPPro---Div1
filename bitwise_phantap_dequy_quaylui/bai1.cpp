#include<iostream>
#include<bitset>
#define get_bit(x, y) (((x) >> (y)) & 1)
using namespace std;

void solve(){
    int n;  cin >> n;
    for(int i=0; i<32; ++i) if(get_bit(n, i) == 1){
        cout << i << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}