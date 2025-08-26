#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
int a[100009];
bool check[100009];

long long res;
int mx;
priority_queue<int> qu;

void solve1(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());

    /*
    8 3
    8 7 6 5 4 3 2 1

    8 5 2
    7 4 1
    6 3

    8 2
    8 4 2 1 1 3 5 9

    9 8 5 4 3 2 1 1

    9 5 3 1
    8 4 2 
    1

    */

    mx = a[1];
    res = a[1];
    qu.push(a[1]);

    //cout << a[1] << " ";
    for(int i=2; i<=n; ++i){
        if(1LL * a[i] + k <= 1LL * qu.top())    qu.pop();
        else                                    res += a[i];
        qu.push(a[i]);
    }

    cout << res;
    
}

void solve2(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());

    //for(int i=1; i<=n; ++i) cout << a[i] << " ";    cout << '\n';

    int pos = 1;
    for(int i=1; i<=n; ++i){
        while(pos <= n && check[pos] == true)   pos += 1;
        if(a[i] + k <= a[pos])  check[pos] = true;
        else                    res += a[i];
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve2();
}