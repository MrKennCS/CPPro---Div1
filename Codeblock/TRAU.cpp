#include<bits/stdc++.h>

using namespace std;

void dfs(int x){
    if(x % 1000 == 0)   cout << x << '\n';

    vector<int> v;
    for(int i=0; i<20; ++i) v.push_back(x ^ i);

    dfs(x + 1);
}

int main(){
    //ios_base::sync_with_stdio(false);   cin.tie(0);
    // -Wl,--stack=67108864
    dfs(0);
}
