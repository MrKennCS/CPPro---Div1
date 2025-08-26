#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int a[100009];

void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i=1; i<=n; ++i){

        int l = i + 1;
        int r = n;
        int mid;
        int id = -1;

        while(l <= r){
            mid = (l + r) >> 1;
            if(a[mid] == a[i] + m){
                id = mid;
                break;
            }
            if(a[mid] > a[i] + m)   r = mid - 1;
            else                    l = mid + 1;
        }

        if(id != -1){
            cout << a[i] << " " << a[id] << '\n';
            return ;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}