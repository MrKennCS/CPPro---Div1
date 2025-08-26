#include<iostream>

using namespace std;

int n;
int a[5009];
long long pre[5009];
int res;

void ans(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }

    for(int k=1; k<=n-1; ++k){
        int l=k;
        int r=k+1;
        int suml = a[l];
        int sumr = a[r];
        while(l >= 1 && r <= n){
            if(suml == sumr)    res = max(res, r - l + 1);
            if(suml < sumr){
                l -= 1;
                if(l >= 1)  suml += a[l];
            }else{
                r += 1;
                if(r <= n)  sumr += a[r];
            }
        }
    }

    cout << res;
}

void solve(){
    cin >> n;

    if(n == 2){
        int one, two;
        cin >> one >> two;
        if(one == two)  cout << 2;
        else            cout << 0;
        return ;
    }

    if(n == 3){
        int mot, hai, ba;
        cin >> mot >> hai >> ba;
        if(mot == hai + ba || mot + hai == ba)  cout << 3;
        else                                    cout << 0;
        return ;
    }

    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    
    /*
    6
    2 10  3  2  5  1
    2 12 15 17 22 23

    TEST 1:
    4
    1 10 23 3
    */

    for(int k=2; k<=n-1; ++k){
        int l = k-1;
        int r = k+1;
        /*
        sum_l = pre[k] - pre[l-1]
        sum_r = pre[r] - pre[k-1];
        */
        int sum_l = pre[k-1] - pre[l-1];
        int sum_r = pre[r] - pre[k-1];
        while(l >= 1 && r <= n){
            sum_l = pre[k-1] - pre[l-1];
            sum_r = pre[r] - pre[k-1];
            if(sum_l == sum_r){
                res = max(r - l + 1, res);
            }
            if(sum_l > sum_r)   r += 1;
            else                l -= 1;
        }
        //cout << l << " " << k << " " << r << '\n';
        //cout << sum_l << " " << sum_r << '\n';
    }

    cout << res;

}

void trau(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+2; j<=n; ++j){
            for(int k=i+1; k<j; ++k){
                if(pre[j] - pre[k-1] == pre[k-1] - pre[i-1])    res = max(res, j - i + 1);
            }
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    ans();
}