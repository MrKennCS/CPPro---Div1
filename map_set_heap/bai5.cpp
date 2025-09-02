#include<iostream>
#include<set>

using namespace std;

void solve(){
    int n, q;
    cin >> n;
    set<int> st;
    for(int i=1; i<=n; ++i){
        int tmp;    cin >> tmp;
        st.insert(tmp);
    }
    cin >> q;
    while(q--){
        int x;  cin >> x;
        cout << (st.find(x) != st.end() ? "YES\n" : "NO\n");
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}