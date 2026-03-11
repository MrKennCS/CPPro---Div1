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

const int mod = 1e9 + 7;
int tc = 1;

/*

*/

int n;
string tmp;
string s;
ll res;

void file(){
    if(fopen("TEST.INP", "r")){
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }
}

void solve(){
    cin >> tmp;
    s = " " + tmp;
    n = sz(tmp);

    for(int id=1; id<=n; ++id){
        for(int i=id, j=id; i>=1 && j<=n; --i, ++j){
            if(s[i] == s[j])    res++;
            else                break;
            //for(int k=i; k<=j; ++k) cout << s[k] << " ";    cout << '\n';
        }
        for(int i=id, j=id+1; i>=1 && j<=n; --i, ++j){
            if(s[i] == s[j])    res++;
            else                break;
            //for(int k=i; k<=j; ++k) cout << s[k] << " ";    cout << '\n';
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    while(tc--)  solve();
}
