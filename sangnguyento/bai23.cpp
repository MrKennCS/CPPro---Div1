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

int n, m;

bool cp(int x){
    return (sqrt(x) == (int)sqrt(x));
}

void sub1(){
    //cout << cp(n) << " " << cp(m);
    /*
    int cnt = 0;
    for(int i=1; i<=10; ++i){
        cout << "---------- \ni: " << i << '\n';
        cnt = 0;
        for(int j=1; j<=i; ++j){
            for(int k=j+1; k<=i; ++k){
                //cout << j << " " << k << " "<< '\n';
                if(cp(j * k)){
                    cnt++;
                    cout << j << " " << k << " " << j * k << '\n';
                }
            }
        }
        cout << '\n' << cnt << '\n';
    }
    */
    if(n == 1 || n == 2 || n == 3)                  cout << 0;  
    else if(n == 4 || n == 5 || n == 6 || n == 7)   cout << 1;
    else if(n == 8)                                 cout << 2;
    else                                            cout << 4;
}

void sub2(){

}

void sub3(){

}

void sub4(){

}

void sub5(){

}


void solve(){
    if(n <= 10)             sub1();
    else if(n <= 50)        sub2();
    else if(n <= 1000)      sub3();
    else if(n <= 100000)    sub4();
    else if(n <= 1000000)   sub5();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT
    cin >> n >> m;
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
