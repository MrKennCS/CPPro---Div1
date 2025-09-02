#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <bitset>
#define int long long
#define double long double
#define ii pair<int,int>
#define iii pair<int, ii >
#define fi first
#define se second
#define getbit(x,y) (((x)>>(y))&1)
#define turnon(x,y) ((x)|(1ll<<y))
#define turnof(x,y) ((x)^(1ll<<y))
#define oo 1e18
#define pb push_back
#define all(x) x.begin(),x.end()
#define con(mask) mask=(mask-1)&mask
#define Unique(val) val.erase(unique(val.begin(),val.end()),val.end())

#define ran d_int mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand_ll mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int base = 448;
using namespace std;

int n, k;
int a[1000005], b[1000005];

void sub1() {
    vector<int>val;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            //a[i] + b[j]

            val.push_back(a[i] + b[j]);
        }
    }

    sort(val.begin(), val.end());

    for(int i = 0; i < k; i++) {
        cout << val[i] << " ";
    }
}

int dem(int x) {
    //đếm xem có bao nhiêu số <= x

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        int pos = upper_bound(b + 1, b + n + 1, x - a[i]) - b - 1;

        cnt += pos;
    }
    return cnt;
}

void sub2() {
    int l = -2e9, r = 2e9, x = 2e9 + 1;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(dem(mid) >= k) {
            x = min(x, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    //số ở vị trí k chính là x

    //Bây giờ sẽ lấy hết những thằng bé hơn x ra

    vector<int>val;

    for(int i = 1; i <= n; i++) {
        //a[i] + b[j] < x
        //b[j] < x - a[i]

        int pos = lower_bound(b + 1, b + n + 1, x - a[i]) - b - 1;

        for(int j = 1; j <= pos; j++) {
            val.push_back(a[i] + b[j]);
        }
    }
    
    while(val.size() < k) val.push_back(x);

    sort(val.begin(), val.end());

    for(int i = 0; i < k; i++) {
        cout << val[i] << " ";
    }
}

signed main() {

    #ifndef ONLINE_JUDGE
    freopen("inp.inp","r",stdin);
    freopen("out.out","w",stdout);
    #endif //ONLINE_JUDGE


    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) cin >> b[i];

    sort(b + 1, b + n + 1);

    if(n <= 1000) sub1();
    else sub2();

}
//      ProTeam
//(¯`·.·´¯) (¯`·.·´¯)
//`·.¸(¯`·.·´¯)¸ .·
//×°× ` ·.¸.·´ ×°×