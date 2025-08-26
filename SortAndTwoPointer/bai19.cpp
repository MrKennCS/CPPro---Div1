#include<iostream>

using namespace std;

int n;
string s;
int pre[100009];
int cnt[30];

void solve(){
    cin >> n >> s;
    s = " " + s;
    for(int i=1; i<=n; ++i){
        cnt[s[i] - 'a'] += 1;
        pre[i] = pre[i-1] + (cnt[s[i] - 'a'] == 1);
    }

    /*
    1 2 2 2     -> 2/4
    1 2 2 2 3 3 -> 3/6

    1
    1
    2/3
    2/4
    3/5
    3/6
    */
    int l=1;
    for(int r=1; r<=n; ++r){
        while()
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}