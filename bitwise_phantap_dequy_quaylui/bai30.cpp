#include<iostream>
#include<vector>
#include<set>
#define sz(a) (int)a.size()
#define pb push_back

using namespace std;

int n;
set<string> st;

void backtrack(string s){
    if(sz(s) == n){
        st.insert(s);
    }
    else{
        string th1 = "(" + s + ")";
        string th2 = s + "()";
        string th3 = "()" + s;
        backtrack(th1);
        backtrack(th2);
        backtrack(th3);
    }
}

void solve(){
    cin >> n;

    string s = "";
    backtrack(s);
    cout << sz(st) << '\n'; 
    /*

    */
   for(set<string>::iterator it=st.begin(); it!=st.end(); ++it){
       cout << (*it) << '\n';
   }
}

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}