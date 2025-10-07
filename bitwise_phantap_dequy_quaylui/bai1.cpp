#include<iostream>
#include<stack>
#define int long long
#define get_bit(x, y) (((x) >> (y)) & 1)

using namespace std;

int n;
stack<int> st;

int mul(int a, int b){
    int res = 0;
    while(b){
        if(b & 1)   res += a;
        a += a;
        b /= 2;
    }
    return res;
}

int pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)   res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void solve(){
    cin >> n;

    for(int i=31; i>=0; --i){
        if(n >= (1LL << i)){
            //cout << i << " " << n << '\n';
            st.push(i);
            n -= (1LL << i);
        }  
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

signed main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();

}