#include<iostream>

using namespace std;

int n, x;
int uoc[1000009];

void start(){
    for(int i=1; i<=1000000; ++i){
        for(int j=i; j<=1000000; j+=i){
            uoc[j] += 1;
        }
    }
}

void solve(){
    cin >> x;
    cout << uoc[x] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    start();

    cin >> n;
    while(n--)  solve();
}