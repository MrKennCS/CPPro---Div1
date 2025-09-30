#include<iostream>
#include<stack>
#define sz(a) (int)a.size()
using namespace std;

int k;
string tmp;
string s = "";
stack<int> st;
stack<int> res;

void solve(){
    cin >> k >> tmp;
    for(int i=0; i<sz(tmp); ++i){
        if('0' <= tmp[i] && tmp[i] <= '9'){
            s += tmp[i];
        }
    }
    k = sz(s) - k;
    for(int i=0; i<sz(s); ++i){
        while(k > 0 && !st.empty() && st.top() > (s[i] - '0')){
            st.pop();
            k--;
        }
        st.push(s[i] - '0');
    }

    while(k > 0){
        st.pop();
        k--;
    }

    while(!st.empty()){
        res.push(st.top());
        st.pop();
    }

    while(!res.empty()){
        cout << res.top();
        res.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}