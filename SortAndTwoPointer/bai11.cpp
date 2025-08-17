#include<iostream>

using namespace std;

int n;
int a[200009];
vector<int> mark(200009, 0);
int cur;
int res;

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    for(int i=1; i<=n; ++i){
        int j=i;
        cur = 0;
        while(j >= 1){
            if(cnt[j] == 1) break;
            cnt[a[j]] += 1;
            cur += 1;
            j -= 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve()
}