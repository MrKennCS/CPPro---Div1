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
vector<ii> t(100005, {-1, -1});
int l, r, mid, ans;

bool check(int x){
    vector<ii> bo;
    bo.pb({-1, -1});

    int sum = 0;
    int pos = 1;
    int max_r = t[1].se;
    bool du = false;

    bo.pb({t[1].fi, t[1].se});

    for(int i=2; i<=n; ++i){
        if(max_r >= t[i].fi){
            if(max_r >= t[i].se)    du = true;
            else    bo.pb({t[i].fi, t[i].se});
            max_r = max(max_r, t[i].se);
        }
        else{
            bo.pb({t[i].fi, t[i].se});
            sum += (max_r - t[pos].fi);
            //cout << sum << '\n';
            pos = i;
            max_r = t[i].se;
        }
        //cout << max_r << '\n';
    }
    sum += (max_r - t[pos].fi);
    bo.pb({2e9, 2e9});

    //cout << du;
    if(sum < x) return false;

    if(du)  return true;

    int m = sz(bo) - 2;
    for(int i=1; i<=m; ++i){
        int tmp = sum;
        
        int left = max(bo[i - 1].se, bo[i].fi);
        int right = min(bo[i + 1].fi, bo[i].se);
        int time = max(0, right - left);

        tmp -= time;
        
        if(tmp >= x)    return true;
    }

    return false;
}

bool cmp(ii a, ii b){
    if(a.fi == b.fi)    return (a.se > b.se);
    return a.fi < b.fi;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> t[i].fi >> t[i].se;

    sort(t.begin() + 1, t.begin() + n + 1, cmp);
    //for(int i=1; i<=n; ++i) cout << t[i].fi << " " << t[i].se << '\n';
    //check(10);

    l = 1;
    r = 1e9 + 3;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        }else   r = mid - 1;
    }

    cout << ans;
    /*
    */
}

void solve1(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> t[i].fi >> t[i].se;

    sort(t.begin() + 1, t.begin() + n + 1);

    int best_min = 1e9 + 5;
    int max_r = -1;
    int sum = 0;
    bool du = false;

    for(int i=1; i<=n; ++i){
        if(max_r >= t[i].fi){
            if(max_r >= t[i].se)    du = true;
            max_r = max(max_r, t[i].se);
        }else{
            int chong = max(0, max_r - t[i].fi);
            max_r = max(max_r, t[i].se);
            sum += ((max_r - t[i].fi) - chong);
        }
    }

    int nhonhat = 2e9;
    
    if(du){
        cout << sum;
        return ;
    }else{
        for(int i=1; i<=n; ++i){
            int left;
            int right;

            if(i == 1)  left = t[1].fi;
            else        left = max(t[i].fi, t[i - 1].se);

            if(r == 1)  right = t[n].se;
            else        right = min(t[i].se, t[i + 1].fi);

            int time = max(0, right - left);

            nhonhat = min(time, nhonhat);
        }
    }
    cout << sum << " " << nhonhat << '\n';
    cout << sum - nhonhat;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    file();

    // INPUT

    // END_INPUT

    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif
    
    while(tc--)  solve1();
    
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "\n[Time: " << duration.count() << " ms]\n"; 
    #endif
}
