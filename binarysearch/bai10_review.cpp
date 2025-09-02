#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;

int n;
ll k;
int a[100009];
int b[100009];
<<<<<<< HEAD:SortAndTwoPointer/binarysearch/bai10.cpp
int c[1000009];
int id=1;

=======
>>>>>>> 534ff79f31667b3929cd4c9d4cfe13737f430a22:binarysearch/bai10_review.cpp

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    
<<<<<<< HEAD:SortAndTwoPointer/binarysearch/bai10.cpp
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            c[id] = a[i] + b[j];
            id += 1;
        }
    }

    sort(c + 1, c + n*n + 1);

    for(int i=1; i<=k; ++i)   cout << c[i] << " ";
=======
>>>>>>> 534ff79f31667b3929cd4c9d4cfe13737f430a22:binarysearch/bai10_review.cpp
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);
    solve();
}