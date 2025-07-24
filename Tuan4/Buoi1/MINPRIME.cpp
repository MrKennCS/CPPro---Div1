/*
    TEST kien thuc moi:

    Xay dung ham minprime[i]: uoc nguyen to nho nhat cua so i

    Gioi han: i ~ 1e6;
*/

#include<iostream>
#include<vector>
#define sz(a) (int)a.size()

using namespace std;

const int maxn = 1e6 + 5;

int minprime[maxn];

vector<int> factor;
vector<int> pow;

void sieve(){
    for(int i=2; i*i<=maxn-5; ++i){
        if(minprime[i] == 0){
            for(int j=i*i; j<=maxn-5; j+=i){
                if(minprime[j] == 0){
                    minprime[j] = i;
                }
            }
        }
    }
    for(int i=2; i<=maxn-5; ++i){
        if(minprime[i] == 0)    minprime[i] = i;
    }
}



void solve(){
    sieve();
    int n;  cin >> n;
    while(n != 1){
        factor.push_back(minprime[n]);
        n /= minprime[n];
    }
    if(n > 1)   factor.push_back(n);
    for(int i=0; i<sz(factor); ++i) cout << factor[i] << " ";
    /*
    */
    
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}