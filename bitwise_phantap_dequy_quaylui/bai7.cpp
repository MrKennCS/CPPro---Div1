#include<iostream>
#define get_bit(x, y)   (((x) >> (y)) & 1)
using namespace std;

int q;

int mul(int a, int b){
    int res = 0;
    while(b){
        if(b & 1)   res += a;
        a += a;
        b /= 2;
    }
    return res;
}

int pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)   res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void solve(){
    int a;
    cin >> a;

    int cnt = 0;

    for(int i=0; i<32; ++i){
        if(get_bit(a, i) == 1)  cnt++;
    }

    cout << pow(2, cnt) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}