#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;

int n;
ll k;
int a[100005];

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    int l, r;
    l = 1;
    r = n;

    while(l >= r){
        /*
        so luong doan tu 1 -> l can tang la (l - 1 + 1)
        so luong doan tu n -> r can tang la (n - r + 1)

        
        */
       if(a[l] == a[l+1])
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}