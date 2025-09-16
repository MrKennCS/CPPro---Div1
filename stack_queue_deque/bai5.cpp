#include<iostream>
#include<stack>
#define sz(a) (int)a.size()

using namespace std;

stack<char> st;
string s;
int n;
long long num;
int x;

void solve(){
    cin >> s;
    n = sz(s);

    for(int i=0; i<n; ++i){
        if(s[i] == '('){
            st.push(0);
        }else if(s[i] == 'C'){
            st.push(12);
        }else if(s[i] == 'H'){
            st.push(1);
        }else if(s[i] == 'O'){
            st.push(16);
        }else if('0' <= s[i] && s[i] <= '9'){
            x = s[i] - '0';
            num = st.top() * x;
            st.pop();
            st.push(num);
        }else if(s[i] == ')'){
            num = 0;
            while(st.top() != 0 && !st.empty()){
                num += st.top();
                st.pop();
            }
            st.pop();
            st.push(num);
        }
    }
    num = 0;
    while(!st.empty()){
        cout << st.top() << " ";
        num += st.top();
        st.pop();
    }
    cout << num;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}