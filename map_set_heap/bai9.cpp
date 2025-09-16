#include<iostream>
#include<stack>

using namespace std;

int n, m;
int a[1005][1005];
int hi[1005];
int l[1005], r[1005];
long long res;

/*
11 13
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 1 1 1 1 1 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 1 1
0 0 0 0 0 1 0 0 0 0 0 1 1

*/
void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j] == 0)    hi[j] = 0;
            else                hi[j] += 1;
            //cout << hi[j] << " ";
        }

        stack<int> st;
        for(int j=1; j<=m; ++j){
            while(!st.empty() && hi[j] <= hi[st.top()])    st.pop();
            //st.top la thang dau tien < hi[j]
            if(!st.empty()) l[j] = st.top() + 1;
            else            l[j] = 1;
            st.push(j);
        }
        while(!st.empty())  st.pop();
        for(int j=m; j>=1; --j){
            while(!st.empty() && hi[j] <= hi[st.top()])    st.pop();
            //st.top la thang dau tien < hi[j]
            if(!st.empty()) r[j] = st.top() - 1;
            else            r[j] = m;
            st.push(j);
        }
        //cout << '\n';
        for(int j=1; j<=m; ++j){
            res = max(res, 1LL * (r[j] - l[j] + 1) * hi[j]);
        }

    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}