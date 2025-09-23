#include<iostream>
#include<stack>

using namespace std;

int n;
int a[100009];
stack<int> st;
int lmax[100009], rmax[100009];
int lmin[100009], rmin[100009];
long long res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<=n; ++i){
        while(!st.empty() && a[st.top()] < a[i])   st.pop();
        lmax[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    }
    while(!st.empty())  st.pop();

    for(int i=n; i>=1; --i){
        while(!st.empty() && a[st.top()] <= a[i])   st.pop();
        rmax[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    }
    while(!st.empty())  st.pop();

    for(int i=1; i<=n; ++i){
        res += 1LL * (rmax[i] - i + 1) * (i - lmax[i] + 1) * a[i];
    }

    for(int i=1; i<=n; ++i){
        while(!st.empty() && a[st.top()] > a[i])   st.pop();
        lmin[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    }
    while(!st.empty())  st.pop();

    for(int i=n; i>=1; --i){
        while(!st.empty() && a[st.top()] >= a[i])   st.pop();
        rmin[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    }
    while(!st.empty())  st.pop();

    for(int i=1; i<=n; ++i){
        res -= 1LL * (rmin[i] - i + 1) * (i - lmin[i] + 1) * a[i];
    }

    //for(int i=1; i<=n; ++i) cout << lmax[i] << " " << rmax[i] << '\n';
    //for(int i=1; i<=n; ++i) cout << lmin[i] << " " << rmin[i] << '\n';

    cout << res;

}

/*
4
1 4 6 2
*/

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}