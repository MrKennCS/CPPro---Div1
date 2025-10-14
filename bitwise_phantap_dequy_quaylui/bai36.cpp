#include<iostream>
#include<stack>
#define ll long long

using namespace std;

int q, n, m;
int a[20];
ll Pow[20];
stack<int> val;
stack<int> dau;

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(ll mask=0; mask<Pow[n-1]; ++mask){
        int tmp = mask;
        if(tmp % 3 == 0){
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;

    Pow[0] = 1;
    for(int i=1; i<=20; ++i){
        Pow[i] = Pow[i-1] * 3;
    }

    while(q--)  solve();
}