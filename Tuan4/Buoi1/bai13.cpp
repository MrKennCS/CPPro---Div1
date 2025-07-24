#include<iostream>

using namespace std;

int n;
int a[100009];
int mu[100009];

int factor(int num){
    if(num == 1)    return 0;
    if(num == 2 || num == 3)    return 1;
    
    int res = 0;
    for(int i=2; i*i<=num; ++i){
        int mu_i = 0;
        while(num % i == 0){
            mu_i += 1;
            num /= i;
        }
        res += mu_i;
    }

    if(num > 1) res += 1;
    return res;
}

void solve(){
    cin >> n;
    int res = 0;
    int mx = -1;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        int fact = factor(a[i]);
        res += fact;
        mx = max(mx, fact);
    }
    cout << res - mx;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}