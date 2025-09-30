#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fi first
#define se second
#define sz(a) (int)a.size()
using namespace std;

int q, m, n;
int l, r, mid, res;
vector<pair<int, int>> a;

bool check(int x){
    vector<pair<int, int>> xe;
    for(int i=1; i<=x; ++i) xe.push_back(a[i]);

    sort(xe.begin(), xe.end());

    int pos = 0;
    priority_queue<int, vector<int>, greater<int>> qu;
    for(int i=1; i<=m; ++i){
        while(pos < sz(xe) && xe[pos].fi <= i){
            qu.push(xe[pos].se);    
            pos++;
        }
        if(!qu.empty()){
            int tmp = qu.top();
            if(tmp < i) return 0;
            qu.pop();
        }
    }

    if(!qu.empty()) return 0;
    else            return 1;

}
/*
1
4 6
1 2
1 2
1 3
1 3
2 4
1 4

1 2 3 4 5 6

*/
void solve(){
    cin >> m >> n;
    for(int i=1; i<=n; ++i){
        int tm1, tm2;   cin >> tm1 >> tm2;
        a.push_back({tm1, tm2});
    }
    l = 1;
    r = n;
    res = 0;

    while(l <= r){
        mid = (l + r) >> 1;
        if(check(mid)){
            l = mid + 1;
            res = max(res, mid);
        }else   r = mid - 1;
    }

    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}