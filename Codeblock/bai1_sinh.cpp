#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll randInt(ll l, ll r){
    ll res = 0;
    for(int i=0; i<4; ++i)  res = (res << 15) ^ (rand() & ((1 << 15) - 1));
    return l + rand() % (r - l + 1);
}

int main(){
    freopen("bai1.INP", "w", stdout);
    srand(time(nullptr));

    int a = randInt(1, 100);
    int b = randInt(1, 100);

    cout << a << " " << b;
    cerr << "INPUT: " << a << " " << b;
}
