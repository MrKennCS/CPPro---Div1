#include<iostream>
#include<algorithm>

using namespace std;

int n, h;
int a[500009];
int b[250009];
int c[250009];
int sz_b, sz_c;
int l, r, mid, res1, res2;
int ans1 = 200009, ans2;
void solve(){
    cin >> n >> h;

    for(int i=1; i<=n; ++i){
        if(i & 1)   cin >> b[sz_b + 1], sz_b += 1;
        else        cin >> c[sz_c + 1], sz_c += 1;
    }

    sort(b + 1, b + sz_b + 1);
    sort(c + 1, c + sz_c + 1);

    for(int i=1; i<=sz_b; ++i)  cout << b[i] << " ";    cout << '\n';
    for(int i=1; i<=sz_c; ++i)  cout << c[i] << " ";    cout << '\n';

    for(int i=1; i<=h; ++i){
        // tim vi tri mid be nhat ma b[mid] >= i
        l = 1;
        r = sz_b;

        while(l <= r){
            mid = (l + r) >> 1;
            if(i <= b[mid]){
                r = mid - 1;
                res1 = mid;
            }else   l = mid + 1;
        }
        if(b[res1] < i)  res1 += 1;
        //cout << sz_b - res + 1 << " ";
        int j = h - i + 1;
        l = 1;
        r = sz_c;
        // 2 2 3 3 3 4 4
        // tim vi tri be nhat ma >= j
        while(l <= r){
            mid = (l + r) >> 1;
            if(c[mid] >= j){
                res2 = mid;
                r = mid - 1;
            }else   l = mid + 1;
        }
        if(c[res2] < j)  res2 = sz_c + 1;
        //cout << sz_c - res + 1 << " ";

        if(ans1 >= sz_b - res1 + sz_c - res2 + 2){
            if(ans1 == sz_b - res1 + sz_c - res2 + 2)   ans2 += 1;
            else{
                ans2 = 1;
                ans1 = sz_b - res1 + sz_c - res2 + 2;
            }
        }
    }
    cout << ans1 << " " << ans2;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}