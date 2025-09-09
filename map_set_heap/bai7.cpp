#include<iostream>
#include<set>
#define sz(a) (int)a.size()
using namespace std;

int n, len, d;
set<int> st;
int a[1000009];
int l, r;

void solve(){
    cin >> n >> len >> d;
    for(int i=1; i<=n; ++i) cin >> a[i];

    l = 1;
    r = 1;

    while(st.empty() || sz(st) <= len){
        cout << a[r] << " ";
        st.insert(a[r]);
        r += 1;
    }
    cout << "sz: " << sz(st) << '\n';

    for(set<int>::iterator it=st.begin(); it!=st.end(); ++it){
        cout << *it << " ";
    }
    /*
    while(r <= n){
        
        while(st.empty() || sz(st) < len){
            st.insert(a[r]);
            r += 1;
        }

    }
    */


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}