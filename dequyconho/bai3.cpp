#include<iostream>

using namespace std;

int n, q;
int a[500009];
int res[500009];

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;



    a[0] = 0;
    a[1] = 1;
    res[0] = 0;
    res[1] = 1;

    for(int i=1; i<=250000; ++i){
        a[i*2] = a[i];
        a[i*2 + 1] = a[i] + a[i+1];
        res[i*2] = max(res[i*2 - 1], a[i*2]);
        res[i*2+1] = max(res[i*2], a[i*2 + 1]);
    }

    while(q--){
        cin >> n;
        cout << res[n] << '\n';
    }

}