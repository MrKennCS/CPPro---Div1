#include<iostream>
#include<unordered_map>

using namespace std;

int n, k;
int a[1000009];
long long res;
unordered_map<int, int> cnt;
unordered_map<int, bool> mark;

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i){    cin >> a[i];    cnt[a[i]] += 1; }
    for(int i=1; i<=n; ++i){
        if(a[i]*2 == k){
            res += (cnt[2*a[i]]*(cnt[2*a[i]]-1)/2);
            mark[a[i]] =
        }else   

    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}