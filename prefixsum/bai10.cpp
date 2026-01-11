#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

const int limN = 1e6 + 3;
const int lim = 5e3;

int n;
int a[limN];
int pre[limN];
int b[lim];
int c[lim];
bool snt[limN];
int pos;
int previous;

ll sum;
ll res;

void sieve(){
    memset(snt, true, sizeof(snt));
    snt[0] = snt[1] = false;
    foru(i, 2, n){
        if(snt[i]){
            for(int j=i*i; j<=n; j+=i){
                snt[j] = false;
            }
        }
    }
}

void solve(){
    cin >> n;

    sieve();
    res = -1e6 - 6;
    for(int i=1; i<=n; ++i) if(snt[i])  res = max(res, 1LL*i);

    foru(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    previous = 2;
    pos = 1;

    for(int i=3; i<=n; ++i){
        if(snt[i]){
            b[pos] = pre[i] - pre[previous - 1];
            c[pos] = a[i];
            previous = i;
            pos++;
        }
    }


    foru(i, 1, pos - 1){
        sum += b[i];
        sum -= c[i - 1];
        if(sum < 0) sum = 0;
        res = max(res, sum);
    }

    cout << res;

    /*
    foru(i, 1, pos) cout << b[i] << " ";    
    cout << '\n';
    foru(i, 1, pos) cout << c[i] << " ";    
    cout << '\n';
    */
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}