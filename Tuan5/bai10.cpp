#include<iostream>
#include<vector>

using namespace std;

const int lim = 1e6;
vector<bool> isPrime(lim + 6, true);

int a[lim + 9];
long long pre[lim + 9];
int n;

int snt;
int previous[lim + 9];
long long sum;
long long res;

void sieve(){
    isPrime[0] = isPrime[1] = false;
    snt = 2;
    for(int i=2; i*i<=lim; ++i){
        if(isPrime[i]){
            previous[i] = snt;
            snt = i;
            for(int j=i*i; j<=lim; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    /*
    11
    9  5 -2  6 -1  1 -3  5 -2 -1  4

    8
    1  2  3  4  5  6  7  8
    1 -9  5 -4 -2  1  2 -1
    1 -8 -3 -7 -9 -8 -6 -7

    8
    1  2  5 -4 -2  1  2 -1

pre 9 14 12 18 17 18 15 20 18 17 21
l   0  2  2  0  2  0  
       5  5     8     8          
        3
    
    goi l[i] la vi tri snt voi l[i] <= i sao cho tong [l[i], i] la lon nhat
    duy tri sum la tong lon nhat cua cac doan dep khi duyet tuyen tinh
    */

    sum = (a[2] < 0 ? 0 : a[2]);
    //for(int i=1; i<=n; ++i) cout << pre[i] << " ";  cout << '\n';
    for(int i=3; i<=n; ++i){
        if(isPrime[i]){
            sum += (pre[i] - pre[previous[i]]);
            if(sum < 0) sum = a[i];
            //cout << "(l, r): " << previous[i] << " " << i << " | Sum: " << sum <<'\n';
            //cout << "(a, b, c): " << pre[i] << " " << pre[previous[i]]<< '\n';
            //cout << pre[i] - pre[previous[i]] << '\n';
            res = max(res, sum);
        }
    }
    for(int i=2; i<=n; ++i) if(isPrime[i])  res = max(res, 1LL * a[i]);
    cout << res;
    /*
    */

}
/*
1 -> 1e6 co 78498 snt
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    sieve();
    solve();
}
