#include<iostream>
#include<set>

using namespace std;

void solve(){
    int n, m;   cin >> n >> m;
    set<int> st;
    for(int i=1; i<=n; ++i){
        int tmp;    cin >> tmp;
        st.insert(tmp);
    }
    for(int i=1; i<=m; ++i){
        int tmp;    cin >> tmp;
        st.insert(tmp);
    }
    for(set<int>::iterator it=st.begin(); it!=st.end(); ++it){
        cout << *it << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}