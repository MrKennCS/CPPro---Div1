#include<iostream>

using namespace std;

int n;
int a[100009];
int pre[100009];
int mark[1000000];
int res;

void solve(){
    cin >> n;

    mark[0] = 1;

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + (a[i] == 1 ? 1 : -1);
    }
    for(int i=1; i<=n; ++i){
        if(mark[pre[i]] == 0)   mark[pre[i]] = i;
        else{
            res = max(res, i - mark[pre[i]]);
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}