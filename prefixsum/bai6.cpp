#include<bits/stdc++.h>
#define ll long long 
#define foru(i, a, b) for(int i=a; i<=b; ++i)
#define ford(i, a, b) for(int i=a; i>=b; --i)
#define unomap unordered_map

using namespace std; 

const int limN = 1e5 + 3;
const int offset = 1e5;
int pos[2 * limN];
int pre[limN];
int a[limN];
int n;
int res;

void solve(){
    cin >> n;
    foru(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + (a[i] == 0 ? -1 : 1);
    }

    memset(pos, -1, sizeof(pos));
    pos[offset] = 0;

    foru(i, 1, n){
        if(pos[pre[i] + offset] == -1)   pos[pre[i] + offset] = i;
        else                    res = max(res, i - pos[pre[i] + offset]);
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}