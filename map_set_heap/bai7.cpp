#include<iostream>
#include<set>
#define sz(a) (int)a.size()
using namespace std;

int n, len, d;
set<int> st;
int a[1000009];
int l, r;
long long res;
void solve(){
    cin >> n >> len >> d;
    for(int i=1; i<=n; ++i) cin >> a[i];

    l=1;
    for(r=1; r<=n; ++r){
        st.insert(a[r]);

        while(l < r && (*st.rbegin() - *st.begin()) > d){
            st.erase(st.find(a[l]));
            l += 1;
        }

        res += (max(0LL, 1LL*r - l + 1));
    }

    cout << res;
    


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}