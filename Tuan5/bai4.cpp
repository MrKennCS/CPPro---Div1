#include<bits/stdc++.h>

using namespace std;

int n;
int a[100009];
int pre[100009];
int res;
unordered_map<long long, int> mp;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + (a[i] == 0 ? -1 : 1);
        //cout << pre[i] << " ";
    }
    mp[pre[0]] = 1;
    for(int i=1; i<=n; ++i){
        if(mp[pre[i]] == 0) mp[pre[i]] = i;
        else                res = max(res, i - mp[pre[i]]);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}