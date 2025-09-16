#include<iostream>
#include<stack>
#define sz(a) (int)a.size()
using namespace std;

int n;
int a[500009];
long long res;
stack<pair<int, int>> st;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        while(!st.empty() && a[i] > st.top().first){
            res += st.top().second;
            st.pop();
        }
        if(st.empty()) st.push({a[i], 1});
        else{
            if(st.top().first == a[i]){
                res += st.top().second;
                st.top().second += 1;
                if(sz(st) > 1)  res += 1;
            }else{
                res += 1;
                st.push({a[i], 1});
            }
        }
    }    

    cout << res;


}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}