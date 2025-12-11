#include<iostream>
#include<cmath>

#define ull unsigned long long
#define ll long long
using namespace std;

ll n, k, t;
ll tmp;
ll res;

void solve(){
    cin >> n >> k >> t;

    tmp = k;
    while(n > 0){
        n -= tmp;
        tmp += k;
        res += t;
    }

    cout << res;
}

void review(){
    /*
    10 3 7

    3

    6

    9

    n*(2*k + (n-1)*k)/2

    */
    cin >> n >> k >> t;
    long long res = 1;
    while(k * (res + 1) * res / 2 < n) res++;
    cout << res * t;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    review();
}

/*
Hoac co the dung cong thuc:

x*(x+1)*k/2


*/