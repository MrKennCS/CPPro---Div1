#include<iostream>
#define ll long long

using namespace std;

int n;
int a[1000009];
ll sum;
ll res;
int check;

void backtrack(int valid, int pos){
    if(valid == 3)  backtrack(1, pos + 1);
    else{
        sum += a[pos];

        res = max(res, sum);

        backtrack(valid + 1, pos + 1);
    }
}

int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    backtrack(1, 1);
}