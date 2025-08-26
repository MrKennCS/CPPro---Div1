#include<iostream>
#include<unordered_map>

using namespace std;

int n;
int a[200009];
unordered_map<int, int> cnt;
int res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    int l = 1;
    for(int r=1; r<=n; ++r){
        cnt[a[r]] += 1;
        if(cnt[a[r]] == 2){
            while(cnt[a[l]] < 2){
                l += 1;
                if(cnt[a[l]] == 1)  cnt[a[l]] = 0;
            }
            cnt[a[r]] -= 1;
            l += 1;
        }
        res = max(res, r - l + 1);  
    }
    
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}