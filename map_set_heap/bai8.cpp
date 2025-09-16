#include<iostream>
#include<stack>

using namespace std;

int q, n;
int a[100009];
stack<int> st;
stack<int> res;
void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    while(!st.empty())  st.pop();
    
    for(int i=n; i>=1; --i){
        while(!st.empty() && st.top() <= a[i])  st.pop();
        res.push(st.empty() ? -1 : st.top());
        st.push(a[i]);
    }

    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}