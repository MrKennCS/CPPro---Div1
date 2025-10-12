#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define pb push_back
#define ll long long
#define sz(a) (int)a.size()
using namespace std;

int n;
int a[20];
int Pow[20];
vector<int> res;
stack<int> st;

int mul(int a, int b){
    int res = 0;
    while(b){
        if(b & 1)   res += a;
        a += a;
        b /= 2;
    }
    return res;
}

int pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)   res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    Pow[0] = 1;
    for(int i=1; i<=n; ++i) Pow[i] = Pow[i-1] * 2;

    for(int mask=0; mask<Pow[n]; ++mask){
        int tmp = mask;
        int sum = 0;
        //cout << "Mask: " << mask << '\n' << "I: " << '\n';
        for(int i=0; i<n; ++i){
            if(tmp % 2 == 1)    sum += a[i+1];
            tmp /= 2;
        }
        res.pb(sum);
        //cout << '\n';
    }

    sort(res.begin(), res.end());

    for(int i=1; i<sz(res); ++i)    cout << res[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    //int a, b;   cin >> a >> b;
    //cout << pow(a, b);

    solve();
}