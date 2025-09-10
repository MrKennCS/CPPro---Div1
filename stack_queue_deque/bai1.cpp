#include<iostream>
#include<stack>
#include<vector>
#define sz(a) (int)a.size()
using namespace std;

int q, n;
string s;
vector<char> vec;

void solve(){
    cin >> s;
    n = sz(s);
    while(!vec.empty()) vec.pop_back();
    for(int i=0; i<n; ++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')   vec.push_back(s[i]);
        else{
            if(vec.empty()){
                cout << "NO\n";
                return ;
            }
            if(vec[sz(vec)-1] == '(' && s[i] != ')'){
                cout << "NO\n";
                return ;
            }
            if(vec[sz(vec)-1] == '[' && s[i] != ']'){
                cout << "NO\n";
                return ;
            }
            if(vec[sz(vec)-1] == '{' && s[i] != '}'){
                cout << "NO\n";
                return ;
            }
            vec.pop_back();
        }
    }
    cout << (vec.empty() ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}