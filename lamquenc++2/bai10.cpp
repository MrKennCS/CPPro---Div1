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
    Nx1: Bob có lợi thế rất lớn vì có thể thấy bài của Alice trước khi đi
->  Nếu Bob sở hữu lá bài có thể đánh bại alice thì bob LUÔN THẮNG
=>  Vậy điều kiện thắng của Alice khi này sẽ trở thành: "Alice thắng chỉ khi cô sở hữu lá bài bất bại"

    Gọi x là các là bài từ 1 -> n
        w(x) là tập hợp các lá bài thắng x

=>  Alice thắng khi sở hữu x với w[x] = {}

    Nx2:
    Dựa vào định nghĩa của x và W(x), ta có:

    x = n       -> w(x) = {1}
    x = n - 1   -> w(x) = {n}
    x = n - 2   -> w(x) = {n, n - 1}
    ...
    x = 2       -> w(x) = {n, n - 1, n - 2, ... 3}
    x = 1       -> w(x) = {n - 1, n - 2, ... 3, 2}
*/

int n;
string tmp;
string s;
bool alice;
int cnt;

void solve(){
    cin >> n >> tmp;
    s = " " + tmp;

    alice = false;
    cnt = 0;

    if(n == 1)  cout << (s[1] == 'A' ? "Alice\n" : "Bob\n");
    else{
        if(s[n] == 'A' && s[1] == 'A')  alice = true;

        if(s[n] == 'A' && s[n - 1] == 'A')  alice = true;

        for(int i=1; i<=n; ++i) if(s[i] == 'B') cnt++;

        if(cnt == 1 && s[n] == 'B') alice = true;

        cout << (alice ? "Alice\n" : "Bob\n");

    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> tc;
    while(tc--)  solve();
}
