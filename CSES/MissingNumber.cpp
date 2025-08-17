#include<iostream>
#include<vector>

using namespace std;

int n;
int a[200009];
vector<bool> mark(200009, false);

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);

    cin >> n;

    for(int i=1; i<=n-1; ++i){
        cin >> a[i];
        mark[a[i]] = true;
    }

    for(int i=1; i<=n; ++i){
        if(!mark[i]){
            cout << i;
            return 0;
        }
    }
}