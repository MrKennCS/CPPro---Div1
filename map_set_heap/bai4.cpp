#include<iostream>
#include<set>

using namespace std;

void solve(){
    int n, m;   cin >> n >> m;
    set<int> st1;
    set<int> st2;
    for(int i=1; i<=n; ++i){
        int tmp;    cin >> tmp;
        st1.insert(tmp);
    }
    for(int i=1; i<=m; ++i){
        int tmp;    cin >> tmp;
        if(st1.find(tmp) != st1.end())  st2.insert(tmp);
    }
    for(set<int>::iterator it=st2.begin(); it!=st2.end(); ++it){
        cout << *it << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}