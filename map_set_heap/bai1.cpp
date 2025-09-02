#include<iostream>
#include<set>

using namespace std;

void solve(){
    set<int> st;
    int n;  cin >> n;

    for(int i=1; i<=n; ++i){
        int tmp;    cin >> tmp;
        st.insert(tmp);
    }

    cout << (int)st.size();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}