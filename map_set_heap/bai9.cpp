#include<iostream>
#include<set>
#define sz(a) (int)a.size()
using namespace std;

int n, q;
int a[1009];
int res, cnt;
multiset<int> st;
/*
3
 5
 1 2 3 4 5
 5
 4 4 4 4 2
 6
 1 3 1 5 3 1

1
6
1 3 1 5 3 1
*/
void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n-i+1; ++j){
            st.insert(a[j]);
            cnt++;
            if(cnt == i){
                
                st.erase(st.find(a[j]));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> q;
    while(q--)  solve();
}