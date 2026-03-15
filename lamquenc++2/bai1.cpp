// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define umap unordered_map
#define uset unordered_set

#define sz(a) (int)a.size()
#define getbit(x, y) (((x) >> (y)) & 1)
#define turnon(x, y) ((x) | (1LL << y))
#define turnof(x, y) ((x) ^ (1LL << y))
#define foru(i, a, b)   for(int i=a; i<=b; ++i)
#define ford(i, a, b)   for(int i=a; i>=b; --i)
#define foruc(i, a, b, c)   for(int i=a; i<=b; i+=c)
#define fordc(i, a, b, c)   for(int i=a; i>=b; i-=c)

#define fi first
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define lb lower_bound // >=
#define ub upper_bound // >

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r){
    assert(l <= r);
    return l + rd() % (r - l + 1);
}

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

const int mod = 1e9 + 7;
int tc = 1;

/*

*/

string s;
stack<int> st;
int cur;
int res;

int val(char ch){
    if(ch == 'C')   return 12;
    if(ch == 'H')   return 1;
    if(ch == 'O')   return 16;
    return 0;
}

void solve(){
    cin >> s;

    for(int i=0; i<sz(s); ++i){
        if(s[i] == 'C' || s[i] == 'H' || s[i] == 'O')   st.push(val(s[i]));

        if(s[i] == '(') st.push(-1);

        if(s[i] == ')'){
            cur = 0;
            while(st.top() != -1){
                cur += st.top();
                st.pop();
            }
            st.pop();
            st.push(cur);
        }

        if('2' <= s[i] && s[i] <= '9'){
            cur = st.top() * (s[i] - '0');
            st.pop();
            st.push(cur);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
