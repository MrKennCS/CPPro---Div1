#include<iostream>
#define sz(a) (int)a.size()
using namespace std;



void solve(){
    string s;
    cin >> s;

    int res = 1;
    int cur = 1;

    for(int i=1; i<=sz(s)-1; ++i){
        if(s[i] == s[i-1])  cur += 1;
        else{
            //cout << cur << " ";
            res = max(res, cur);
            cur = 1;
        }
    }
    cout << max(res, cur);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}