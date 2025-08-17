#include<iostream>

using namespace std;

int n;
long long s;
int a[400009];

long long sum;
long long res;
long long sz;

void solve(){
    /*
    7 80
    70 11 32 43 43 11 54

    */
    cin >> n >> s;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        a[i+n] = a[i];
    }

    int i=1;
    int j=1;

    sz = 1;

    while(j <= 2*n){

    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}