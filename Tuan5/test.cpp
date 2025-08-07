#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define xn '\n'
#define pb push_back
using namespace std;
const int N = 1e7+5;
const int M = 1e3+5;
const ll mo = 998244353;

ll n,k;
ll vt;
ll res;
ll cnt;
ll a[N];
ll f[N];

void sng(){
   fill(f+1,f+N+1,1);
   f[0] = f[1] = 0;
   for (long i=2; i<=sqrt(N); i++){
     if (f[i]) for (long j=i*2; j<=N; j+=i)
     f[j] = 0;
   }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sng();
    cin >> n >> k;

    for (long i=1; i<=n; i++){
        if (f[i]) a[i] = a[i-1] + 1; else
            a[i] = a[i-1];
    }

    for (long i=1; i<=n; i++){
        if (f[i])
        vt = lower_bound(a+1,a+n+1,a[i]+k-1)-a; else
        vt = lower_bound(a+1,a+n+1,a[i]+k)-a;
        res += (vt > n ? 0 : n - vt + 1);
    }

    cout << res;
    return 0;
}