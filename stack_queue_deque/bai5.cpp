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

const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
string s;
vector<int> a;

int val(char x){
    if(x == 'C')    return 12;
    if(x == 'H')    return 1;
    return 16;
}

void solve(){
    cin >> s;
    n = sz(s);

    for(int i=0; i<n; ++i){
        if(s[i] == 'C' || s[i] == 'H' || s[i] == 'O')   a.pb(val(s[i]));
        else if(s[i] == '(')                            a.pb(-1);
        else if(s[i] == ')'){
            int sum = 0;
            while(a.back() != -1){
                sum += a.back();
                a.pop_back();
            }
            a.pop_back();
            a.pb(sum);
        }else{
            int sum = a.back() * (s[i] - '0');
            a.pop_back();
            a.pb(sum);
        }
        //for(int i=0; i<sz(a); ++i)  cout << a[i] << " ";    cout << '\n';
    }

    int res = 0;
    for(int i=0; i<sz(a); ++i)  res += a[i];

    cout << res;
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
