#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int n;
pair<int, int> a[1000000];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)    return (a.first > b.first);
    return (a.second > b.second);
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + n + 1, cmp);

    int cnt = 1;
    int res = 0;

    for(int i=1; i<=n; ++i){
        if(cnt == 0)    break;
        cnt -= 1;
        cnt += a[i].second;
        res += a[i].first;
    }

    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}