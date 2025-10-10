#include<iostream>

using namespace std;

int n, k;
int a[35];
bool ok[35];

void sinh(int vt){
    if(vt == k + 1){
        for(int i=1; i<=k; ++i) cout << a[i] << " ";
        cout << '\n';
        return ;
    }

    for(int i=1; i<=n; ++i){
        if(ok[i] == 0){
            a[vt] = i;
            ok[i] = 1;

            sinh(vt + 1);

            ok[i] = 0;
        }
    }
}

void solve(){
    cin >> n >> k;

    sinh(1);
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}