#include<iostream>
#include<queue>
#define sz(a) (int)a.size();

using namespace std;

int cs;
int k, p;

bool cmp(pair<int, int> a, pair<int, int> b){
    return (a->second <= b->second);
}

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> qu;
void solve(){
    while(cin >> cs){
        if(cs == 0) return ;

        if(cs == 1){
            cin >> k >> p;

        }else if(cs == 2){

        }else{

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}