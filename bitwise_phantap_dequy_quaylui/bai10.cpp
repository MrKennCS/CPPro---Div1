#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#define pb push_back
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) % 3)

using namespace std;

int n;
int pow[30];
int res;
vector<int> a, b;
vector<int> mask;
unordered_map<int, int> cnt;

void solve(){
    cin >> n;
    
    for(int i=0; i<n; ++i){
        int h;  cin >> h;
        if(i < n/2) a.pb(h);
        else        b.pb(h);
    }

    pow[0] = 1;
    for(int i=1; i<=n/2+3; ++i) pow[i] = pow[i-1] * 3;

    for(int mask=1; mask<pow[sz(a)]; ++mask){
        int tmp = mask;
        int sum_a = 0;
        int sum_b = 0;
        for(int i=0; i<sz(a); ++i){
            if(tmp % 3 == 1)        sum_a += a[i];
            else if(tmp % 3 == 2)   sum_b += a[i];
            tmp /= 3; 
        }

        // sum_a_1 + sum_a_2 = sum_b_1 + sum_b_2
        // sum_a_1 - sum_b_1 = sum_b_2 - sum_a_2
        cnt[sum_a - sum_b] = max(cnt[sum_a - sum_b], sum_b);
        if(sum_a == sum_b)  res = max(res, sum_b);
    }

    for(int mask=1; mask<pow[sz(b)]; ++mask){
        int tmp = mask;
        int sum_a = 0;
        int sum_b = 0;
        for(int i=0; i<sz(b); ++i){
            if(tmp % 3 == 1)        sum_a += b[i];
            else if(tmp % 3 == 2)   sum_b += b[i];
            tmp /= 3;
        }
        if(sum_a == sum_b)  res = max(res, sum_b);
        if(cnt[sum_b - sum_a])   res = max(res, cnt[sum_b - sum_a] + sum_b);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}