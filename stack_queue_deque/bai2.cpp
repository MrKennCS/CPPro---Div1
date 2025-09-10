#include<iostream>
#include<queue>

using namespace std;

int n, k;
queue<int> qu;
int num, res;

void solve(){
    cin >> n >> k;
    qu.push(n);

    while(!qu.empty()){
        //cout << "HELLO\n";
        num = qu.front();
        qu.pop();
        if(num <= k){
            res += 1;
            //cout << num << " ";
            continue;
        }
        if((num + k) % 2 == 0){
            qu.push((num + k) / 2);
            qu.push((num - k) / 2);
        }else{
            res += 1;
            //cout << num << " ";
        }
    }
    //cout << '\n';
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}