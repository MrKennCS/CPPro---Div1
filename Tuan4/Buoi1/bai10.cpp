#include<iostream>

using namespace std;

int n;

int demuoc(int x){
    int res = 0;
    for(int i=1; i*i<=x; ++i){
        if(x % i == 0)  res += (x/i == i ? 1 : 2);
    }
    return res;
}

void solve(){
    cin >> n;
    cout << demuoc(n) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    int q;  cin >> q;
    while(q--)  solve();
}