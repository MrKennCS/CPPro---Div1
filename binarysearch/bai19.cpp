#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int q;
vector<int> val;
int cnt[105];
int Q[200009];

void solve(){
    cin >> q;
    for(int i=1; i<=q; ++i){
        cin >> Q[i];
        val.push_back(Q[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for(int i=1; i<=q; ++i){
        int dem = 0;
        int x = Q[i];
        x = lower_bound(val.begin(), val.end(), x) - val.begin();
        for(int j=0; j<x; ++j)  dem += cnt[j];
        cnt[x]++;
        cout << dem << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}