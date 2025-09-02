#include<iostream>
#include<map>

using namespace std;

void solve(){
    int n;  cin >> n;
    map<int, int> mp;
    for(int i=1; i<=n; ++i){
        int tmp;    cin >> tmp;
        mp[tmp] += 1;
    }

    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
        cout << it->first << " " << it->second << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}