#include<iostream>
#include<vector>
#include<bitset>
#define sz(a) (int)a.size()
#define get_bit(x, y) (((x) >> (y)) & 1)
#define turnon(x, y) ((x)|(1<<y))
#define turnoff(x, y) ((x)^(1<<y))
using namespace std;

int n;
vector<string> a(30, "");
int dem[200];
int cnt;
int res;
int fin;

void solve(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i];

    for(int mask=0; mask<(1<<n); ++mask){
        fin = 0;
        for(int i=0; i<n; ++i){
            if(get_bit(mask, i) == 1){
                for(int id=0; id<sz(a[i]); ++id){
                    int kitu = a[i][id] - 'a';
                    cout << kitu << " ";
                    turnon(fin, kitu);
                    cout << bitset<26>(fin) << '\n';
                }
            }
        }
        cout << bitset<26>(fin) << '\n';
        if(fin == (1<<26))  res++;
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    //cout << (int)'a' << " " << (int)'z';

    solve();
}