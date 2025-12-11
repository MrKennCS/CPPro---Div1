#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

int n;
ll k;
int a[100005];
int sz1, sz2;
/*
4 5
3 1 7 5

1 3 5 7
*/
void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    int l = 1;
    int r = n;

    sort(a + 1, a + n + 1);

    while(l <= r){
        while(a[l + 1] == a[l]) l++;
        while(a[r - 1] == a[r]) r--;
        sz1 = a[l + 1] - a[l];
        sz2 = a[r] - a[r - 1];

        cout << l << " " << r << " " << sz1 << " " << sz2 << '\n';
        cout << l << " " << n - r + 1 << '\n';
        for(int i=1; i<=n; ++i) cout << a[i] << " ";    cout << "\n\n";
        if((n - r + 1) * sz2 >= l * sz1){
            cout << "R:\n";
            if(k >= (n - r + 1) * sz2){
                k -= (n - r + 1) * sz2;
                r--;
            }
            else{
                while(k >= (n - r + 1)){
                    k -= (n - r + 1);
                    a[r]--;
                }
                cout << a[r] - a[l];
                return ;
            }
        }else{
            cout << "L:\n";
            if(k >= l * sz1){
                k -= l * sz1;
                l++;
            }
            else{
                // khi nay a[r] la thang to nhat
                // res = a[r] - a[l];
                while(k >= l){
                    k -= l;
                    a[l]++;
                }
                cout << a[r] - a[l];
                return ;
            }
        }
        cout << "K: " << k << '\n';
    }
    cout << "KFINAL: " << k;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}