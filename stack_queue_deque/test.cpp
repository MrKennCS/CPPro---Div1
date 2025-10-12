#include<iostream>
#define ll long long
using namespace std;

int n, k, p;
int a[100009];
ll pre[100009];
int q;
ll res;

void solve(){
    //cin >> k >> p;

    int st, ed, mid;
    st = (p % n == 0 ? n : p % n);
    k -= (n - st + 1);
    if(k <= 0){
        k += n;
        ed = k;
        cout << pre[ed] - pre[st-1];
        return ;
    }
    else{
        mid = k / n;
        ed = k - (n * mid);
        if(ed == 0) ed = n;
        cout << mid * (pre[n] - pre[0]) + pre[st+ed] - pre[st-1];
        return ;
    }
    //cout << st << " " << k << " " << mid << " " << ed << '\n';


}
/*
15
5
1 
2 
3 
4 
5
2 7
3 7
4 7
5 7
20 7
21 7
22 7
23 7
24 7
25 7
26 7
27 7
28 7
29 7
30 7
*/
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    //cin >> q;
    cin >> n >> k >> p;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        pre[i+n] = pre[i];
    }
    //while(q--)  solve();
    solve();
}