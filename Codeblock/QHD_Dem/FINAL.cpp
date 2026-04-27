#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 100;
    const string name = "run";
    for(int i=1; i<=n; ++i){
        system((name + ".bat").c_str());
    }
}
/*
#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a; i>=b; --i)
#define getbit(x, y) (((x) >> (y)) & 1)

using namespace std;

const int mod = 1e9 + 7;

void init(){

}

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    if(fopen("CURRENT.INP", "r")){
        freopen("CURRENT.INP", "r", stdin);
        freopen("CURRENT.OUT", "w", stdout);
    }

    init();
    solve();
}
*/
