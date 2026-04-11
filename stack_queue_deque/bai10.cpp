// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

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

const int AM = -2e9;
const int DUONG = 2e9;
const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
int a[100005];

void sub1(){
    ll res = 0;
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            int max_val = -2e9;
            int min_val = 2e9;
            for(int k=i; k<=j; ++k){
                max_val = max(max_val, a[k]);
                min_val = min(min_val, a[k]);
            }
            res += (max_val - min_val);
        }
    }
    cout << res;
}

void sub2(){
    ll res = 0;
    int mn = 2e9;
    int mx = -2e9;
    for(int i=1; i<=n; ++i){
        mn = min(DUONG, a[i]);
        mx = max(AM, a[i]);
        for(int j=i+1; j<=n; ++j){
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            res += (mx - mn);
        }
    }
    cout << res;
}

void sub3(){
    vector<int> lmin(n + 3, 0);
    vector<int> rmin(n + 3, 0);
    vector<int> lmax(n + 3, 0);
    vector<int> rmax(n + 3, 0);
    ll res = 0;

    stack<int> st;
    for(int i=1; i<=n; ++i){
        while(!st.empty() && a[st.top()] >= a[i])   st.pop();
        if(st.empty())  lmin[i] = 1;
        else            lmin[i] = st.top() + 1;
        st.push(i);
    }
    while(!st.empty())  st.pop();
    for(int i=n; i>=1; --i){
        while(!st.empty() && a[st.top()] > a[i])    st.pop();
        if(st.empty())  rmin[i] = n;
        else            rmin[i] = st.top() - 1;
        st.push(i);
    }
    while(!st.empty())  st.pop();
    for(int i=1; i<=n; ++i){
        while(!st.empty() && a[st.top()] <= a[i])   st.pop();
        if(st.empty())  lmax[i] = 1;
        else            lmax[i] = st.top() + 1;
        st.push(i);
    }
    while(!st.empty())  st.pop();
    for(int i=n; i>=1; --i){
        while(!st.empty() && a[st.top()] < a[i])    st.pop();
        if(st.empty())  rmax[i] = n;
        else            rmax[i] = st.top() - 1;
        st.push(i);
    }

    //for(int i=1; i<=n; ++i) cout << lmin[i] << " " << rmin[i] << '\n';  cout << "---\n";
    //for(int i=1; i<=n; ++i) cout << lmax[i] << " " << rmax[i] << '\n';  cout << "---\n";

    for(int i=1; i<=n; ++i){
        // So luong doan con la min: 
        res -= (1ll * (rmin[i] - i + 1) * (i - lmin[i] + 1) * a[i]);
        res += (1ll * (rmax[i] - i + 1) * (i - lmax[i] + 1) * a[i]);
    }

    cout << res;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    if(n <= 100)        sub3();
    else if(n <= 3375)  sub2();
    else                sub3();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT
    
    // END_INPUT

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    while(tc--)  solve();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
