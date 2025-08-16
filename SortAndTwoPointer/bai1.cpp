#include<iostream>
#include<algorithm>
#define sz(a) (int)a.size()
using namespace std;

int n;
string a[100009];
string res = "";
bool cmp(string a, string b){
    return (a+b > b+a);
}  

void solve(){
    cin >> n;

    for(int i=1; i<=n; ++i) cin >> a[i];
    
    sort(a + 1, a + n + 1, cmp);

    for(int i=1; i<=n; ++i) res += a[i];
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}