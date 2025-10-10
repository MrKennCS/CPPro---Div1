#include<iostream>
#include<stack>

using namespace std;

void solve(){
    int n;  cin >> n;
    stack<int> res;
    for(int i=31; i>=0; --i){
        if(n >= (1LL<<i)){
            res.push(i);
            n -= (1LL<<i);
        }
    }
    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);
    solve();
}