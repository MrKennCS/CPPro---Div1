#include<iostream>
#include<bitset>
#include<cstring>
#include<cmath>
#define get_bit(x, y) (((x) >> (y)) & 1)
#define sz(a) (int)a.size()
#define pb push_back

using namespace std;

int n;
string s;
int sum;
int l, r;
const int mod = 1e9 + 7;

void add(int &x, int y){
    x += y;
    if(x >= mod)    x -= mod;
}

void solve(){
    cin >> s;
    n = sz(s);
    
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}