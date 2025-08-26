#include<iostream>

using namespace std;

int n, m;
int arr[10009];
int cnt[10009];
int res;

void solve(){
    /*
    TEST 1:
    6 20  7  9  6  2  1  5

    1  2  5  6  7  9

    a = 1 -> b = 7 : c = 9
    a = 2 -> b = 7 : c = 9
    a = 5 -> b = 6 : c = 9
    a = 6 -> b = 5 : c = 9
    a = 7 -> b = 2 : c = 9
    a = 9 -> b = 2 : c = 7

    TEST 2:
    6 13  7  9  6  2  1  5

    1  2  5  6  7  9

    a = 1 -> b = 2 : c = 9
    a = 2 -> b = 1 : c = 9
    a = 5 -> b = 1 : c = 7
    a = 6 -> b = 2 : c = 5
    a = 7 -> b = 1 : c = 5
    a = 9 -> b = 1 : c = 2
    */

}

void trau(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
        cnt[arr[i]] += 1;
    }
    int id = 1;
    for(int i=1; i<=10000; ++i){
        for(int j=0; j<cnt[i]; ++j){
            arr[id] = i;
            id += 1;
        }
    }
    //for(int i=1; i<=n; ++i) cout << arr[i] << " ";


    for(int k=3; k<=n; ++k){
        int i=1; 
        for(int j=k-1; j>=1; --j){
            if(i >= j)  break;
            while(i + 1 < j && arr[i+1] + arr[j] <= m - arr[k])   i += 1;
            if(arr[i] + arr[j] + arr[k] <= m) res = max(res, arr[i] + arr[j] + arr[k]);
        }
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    trau();
}