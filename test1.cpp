#include<iostream>
#include<stack>
#include<cmath>
#define int long long
using namespace std;

int k;
int num;
int sum;
int cnt;
int remain;
int x;
int fi;
int so_sau;
int tong[10005];
string res = "";
stack<char> st;

void solve(){
    cin >> k;
    num = 0;
    cnt = 0;

    while(sum < k){
        if(num == 0)    num = 1;
        else            num *= 10;
        cnt++;
        sum += 9 * num * cnt;
        tong[cnt] = 9 * num * cnt + tong[cnt-1];
    }

    fi = num - 1;
    //cout << fi << '\n';
    remain = k - tong[cnt - 1];
    //cout << "Remain: " << remain << '\n';
    so_sau = ceil(1.0 * remain / cnt);
    //cout << "So_sau: " << so_sau << " " << (remain - 1) % cnt << '\n';
    //cout << so_sau + fi << " " << (remain - 1) % cnt << '\n';

    for(int i=0; i<=3; ++i){
        int tmp = so_sau + fi + i;
        while(tmp){
            st.push(tmp % 10 + '0');
            tmp /= 10;
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
    }

    for(int i=(remain - 1) % cnt; i<=(remain - 1) % cnt+3; ++i) cout << res[i];
}

main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}