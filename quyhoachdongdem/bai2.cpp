#include<iostream>

using namespace std;

//KHAI BAO
/*
const int mod = 14062008;
const int N = 1e5 + 5;
int n, k;
int a[N];
int dp[N];
*/

//SOLVE
/*
void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=k; ++i) cin >> a[i];

    int pos = 1;
    
    dp[1] = 1;
    for(int i=1; i<=n-1; ++i){
        if(i == a[pos]){
            pos++;
            continue;
        }
        add(dp[i+1], dp[i]);
        add(dp[i+2], dp[i]);
    }

    cout << dp[n];
}
*/

const int N = 1e5 + 5;
const int mod = 14062008;
int n, k;
int hu[N];
int dp[N];

/*
Goi dp[i] la so cach leo len cau thang thu i

do o moi buoc, ta co the co 2 cach leo sau:

TH1: leo len bac thu i + 1
dp[i + 1] += dp[i]

TH2: leo len bac thu i + 2
dp[i + 2] += dp[i]
*/

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void review(){
    cin >> n >> k;

    for(int i=1; i<=k; ++i){
        int tmp;    cin >> tmp;
        hu[tmp] = 1;
    }
    dp[1] = 1;
    for(int i=1; i<=n; ++i){
        if(hu[i] == 1)  continue;
        add(dp[i + 1], dp[i]);
        add(dp[i + 2], dp[i]);
        //dp[i + 1] += dp[i];
        //dp[i + 2] += dp[i];
    }

    /*
    */

    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //solve();
    review();
}