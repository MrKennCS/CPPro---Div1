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
    1
    3
    cab
    cab

    1
    6
    abbabc
    bbaacb

    1
    10
    bcaabababc
    cbbababaac
*/

int n;
string s;
string t;
int check;
int cnt_a, cnt_b, cnt_c;

void solve(){
    cin >> n;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;

    // CODE QUEN RESET BIEN TOAN CUNG -> FIXED
    cnt_a = cnt_b = cnt_c = 0;
    check = 0;

    for(int i=1; i<=n; ++i){
        if      (s[i] == 'a')   cnt_a++;
        else if (s[i] == 'b')   cnt_b++;
        else if (s[i] == 'c')   cnt_c++;

        if      (t[i] == 'a')   cnt_a--;
        else if (t[i] == 'b')   cnt_b--;
        else if (t[i] == 'c')   cnt_c--;

        if(s[i] == t[i])    check++;
    }

    if(check == n){
        cout << "YES\n";
        return ;
    }

    if(cnt_a != 0 || cnt_b != 0 || cnt_c != 0){
        cout << "NO\n";
        return ;
    }

    //cout << int('a') << " " << int('z');
    // 97 - 122
    //cout << '\n';

    for(int i=n; i>=1; --i){
        if(s[i] == t[i])    continue;
        if(s[i] == 'b' && t[i] == 'a'){
            int id = i;
            while(s[id] == 'b' && id > 1) id--;
            if(s[id] == 'c'){
                cout << "NO\n";
                return ;
            }else{
                s[id] = 'b';
                s[i] = 'a';
            }
        }else if(s[i] == 'c' && t[i] == 'b'){
            int id = i;
            while(s[id] == 'c' && id > 1) id--;
            if(s[id] == 'a'){
                cout << "NO\n";
                return ;
            }else{
                s[id] = 'c';
                s[i] = 'b';
            }
        }else{
            cout << "NO\n";
            return ;
        }
        //cout << s << '\n';
    }
    cout << "YES\n";
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> tc;
    while(tc--)  solve();
}
