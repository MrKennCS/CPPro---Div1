#include<iostream>
#include<stack>
#define sz(a) (int)a.size()
using namespace std;

string s;
int n;
stack<char> le;
stack<char> ri;
stack<char> res;

void solve(){
    cin >> s;
    n = sz(s);

    for(int i=0; i<n; ++i){
        if(s[i] == '<'){
            if(!le.empty()){
                ri.push(le.top());
                le.pop();
            }
        }else if(s[i] == '>'){
            if(!ri.empty()){
                le.push(ri.top());
                ri.pop();
            }
        }else if(s[i] == '-'){
            if(!le.empty()) le.pop();
        }else{
            le.push(s[i]);
        }
    }

    while(!le.empty()){
        res.push(le.top());
        le.pop();
    }
    while(!res.empty()){
        cout << res.top();
        res.pop();
    }
    while(!ri.empty()){
        cout << ri.top();
        ri.pop();
    }


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}